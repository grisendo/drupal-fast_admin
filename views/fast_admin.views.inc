<?php

/**
 * @file
 * Provide default views for fast_admin.module.
 *
 * @ingroup views_module_handlers
 */

/**
 * Implements hook_views_default_views().
 */
function fast_admin_views_default_views() {

  $views = array();

  $ctt = node_type_get_types();

  $weight = 0;

  foreach ($ctt as $content_type => $content_type_obj) {

    $has_languages = variable_get('language_content_type_' . $content_type, FALSE);

    $path_name = str_replace('_', '-', $content_type);

    $view = new view;
    $view->name = 'fast_admin__node__' . $content_type;
    $view->description = '';
    $view->tag = 'fast_admin';
    $view->base_table = 'node';
    $view->human_name = 'Fast admin: Node: ' . $content_type_obj->name;
    $view->core = 0;
    $view->api_version = '3.0';
    $view->disabled = FALSE;

    $handler = $view->new_display('default', 'Master', 'default');
    $handler->display->display_options['use_ajax'] = FALSE;
    $handler->display->display_options['access']['type'] = 'perm';
    $handler->display->display_options['access']['perm'] = 'create ' . $content_type . ' content';
    $handler->display->display_options['cache']['type'] = 'none';
    $handler->display->display_options['query']['type'] = 'views_query';
    $handler->display->display_options['query']['options']['query_comment'] = FALSE;
    $handler->display->display_options['exposed_form']['type'] = 'basic';
    $handler->display->display_options['pager']['type'] = 'full';
    $handler->display->display_options['style_plugin'] = 'table';
    $handler->display->display_options['row_plugin'] = 'fields';
    $handler->display->display_options['style_options']['default'] = 'title';
    $handler->display->display_options['style_options']['info'] = array(
      'title' => array(
        'sortable' => 1,
        'default_sort_order' => 'asc',
        'align' => '',
        'separator' => '',
        'empty_column' => 0,
      ),
      'status' => array(
        'sortable' => 1,
        'default_sort_order' => 'asc',
        'align' => '',
        'separator' => '',
        'empty_column' => 0,
      ),
    );

    if (module_exists('statistics')) {
      if (variable_get('statistics_enable_access_log', FALSE)) {
        $handler->display->display_options['style_options']['info']['timestamp'] = array(
          'sortable' => 1,
          'default_sort_order' => 'asc',
          'align' => '',
          'separator' => '',
          'empty_column' => 0,
        );
        $handler->display->display_options['style_options']['info']['daycount'] = array(
          'sortable' => 1,
          'default_sort_order' => 'asc',
          'align' => '',
          'separator' => '',
          'empty_column' => 0,
        );
      }
      if (variable_get('statistics_count_content_views', FALSE)) {
        $handler->display->display_options['style_options']['info']['totalcount'] = array(
          'sortable' => 1,
          'default_sort_order' => 'asc',
          'align' => '',
          'separator' => '',
          'empty_column' => 0,
        );
      }
    }

    if ($has_languages) {
      $handler->display->display_options['style_options']['info']['language'] = array(
        'sortable' => 1,
        'default_sort_order' => 'asc',
        'align' => '',
        'separator' => '',
        'empty_column' => 0,
      );
    }

    if (module_exists('views_bulk_operations')) {
      $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
      $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'node';
      $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
      $handler->display->display_options['fields']['views_bulk_operations']['label'] = 'Operations';
      $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '0';
      $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
      $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
      $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
      $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
        'action::views_bulk_operations_delete_item' => array(
          'selected' => 1,
          'postpone_processing' => 0,
          'skip_confirmation' => 0,
          'override_label' => 0,
          'label' => '',
        ),
        'action::node_publish_action' => array(
          'selected' => 1,
          'postpone_processing' => 0,
          'skip_confirmation' => 0,
          'override_label' => 0,
          'label' => '',
        ),
        'action::node_unpublish_action' => array(
          'selected' => 1,
          'postpone_processing' => 0,
          'skip_confirmation' => 0,
          'override_label' => 0,
          'label' => '',
        ),
      );
    }

    if (module_exists('draggableviews')) { // TO-DO: Mark which entity types are
      $handler->display->display_options['fields']['draggableviews']['id'] = 'draggableviews';
      $handler->display->display_options['fields']['draggableviews']['table'] = 'node';
      $handler->display->display_options['fields']['draggableviews']['field'] = 'draggableviews';
      $handler->display->display_options['fields']['draggableviews']['label'] = 'Drag';
      $handler->display->display_options['fields']['draggableviews']['element_default_classes'] = FALSE;
      $handler->display->display_options['fields']['draggableviews']['hide_alter_empty'] = FALSE;
      $handler->display->display_options['fields']['draggableviews']['draggableviews']['ajax'] = 0;
    }
    elseif (module_exists('weight') && variable_get('weight_enabled_' . $content_type, FALSE)) {
      $handler->display->display_options['fields']['weight']['id'] = 'weight';
      $handler->display->display_options['fields']['weight']['table'] = 'weight_weights';
      $handler->display->display_options['fields']['weight']['field'] = 'weight';
    }

    $handler->display->display_options['fields']['title']['id'] = 'title';
    $handler->display->display_options['fields']['title']['table'] = 'node';
    $handler->display->display_options['fields']['title']['field'] = 'title';
    $handler->display->display_options['fields']['title']['label'] = 'Title';
    $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
    $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
    $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
    $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 0;
    $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 0;
    $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
    $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
    $handler->display->display_options['fields']['title']['alter']['html'] = 0;
    $handler->display->display_options['fields']['title']['hide_empty'] = 0;
    $handler->display->display_options['fields']['title']['empty_zero'] = 0;
    $handler->display->display_options['fields']['title']['link_to_node'] = 1;
    $handler->display->display_options['fields']['status']['id'] = 'status';
    $handler->display->display_options['fields']['status']['table'] = 'node';
    $handler->display->display_options['fields']['status']['field'] = 'status';
    $handler->display->display_options['fields']['status']['label'] = 'Published';
    $handler->display->display_options['fields']['status']['alter']['alter_text'] = 0;
    $handler->display->display_options['fields']['status']['alter']['make_link'] = 0;
    $handler->display->display_options['fields']['status']['alter']['absolute'] = 0;
    $handler->display->display_options['fields']['status']['alter']['external'] = 0;
    $handler->display->display_options['fields']['status']['alter']['replace_spaces'] = 0;
    $handler->display->display_options['fields']['status']['alter']['trim_whitespace'] = 0;
    $handler->display->display_options['fields']['status']['alter']['nl2br'] = 0;
    $handler->display->display_options['fields']['status']['alter']['word_boundary'] = 1;
    $handler->display->display_options['fields']['status']['alter']['ellipsis'] = 1;
    $handler->display->display_options['fields']['status']['alter']['more_link'] = 0;
    $handler->display->display_options['fields']['status']['alter']['strip_tags'] = 0;
    $handler->display->display_options['fields']['status']['alter']['trim'] = 0;
    $handler->display->display_options['fields']['status']['alter']['html'] = 0;
    $handler->display->display_options['fields']['status']['element_label_colon'] = 1;
    $handler->display->display_options['fields']['status']['element_default_classes'] = 1;
    $handler->display->display_options['fields']['status']['hide_empty'] = 0;
    $handler->display->display_options['fields']['status']['empty_zero'] = 0;
    $handler->display->display_options['fields']['status']['hide_alter_empty'] = 1;
    $handler->display->display_options['fields']['status']['type'] = 'unicode-yes-no';
    $handler->display->display_options['fields']['status']['not'] = 0;

    if ($has_languages) {
      $handler->display->display_options['fields']['language']['id'] = 'language';
      $handler->display->display_options['fields']['language']['table'] = 'node';
      $handler->display->display_options['fields']['language']['field'] = 'language';
      $handler->display->display_options['fields']['language']['label'] = 'Language';
    }

    if (module_exists('statistics')) {
      if (variable_get('statistics_enable_access_log', FALSE)) {
        $handler->display->display_options['fields']['timestamp']['id'] = 'timestamp';
        $handler->display->display_options['fields']['timestamp']['table'] = 'node_counter';
        $handler->display->display_options['fields']['timestamp']['field'] = 'timestamp';
        $handler->display->display_options['fields']['timestamp']['date_format'] = 'short';
        $handler->display->display_options['fields']['daycount']['id'] = 'daycount';
        $handler->display->display_options['fields']['daycount']['table'] = 'node_counter';
        $handler->display->display_options['fields']['daycount']['field'] = 'daycount';
      }
      if (variable_get('statistics_count_content_views', FALSE)) {
        $handler->display->display_options['fields']['totalcount']['id'] = 'totalcount';
        $handler->display->display_options['fields']['totalcount']['table'] = 'node_counter';
        $handler->display->display_options['fields']['totalcount']['field'] = 'totalcount';
      }
    }

    $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
    $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
    $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
    $handler->display->display_options['fields']['edit_node']['label'] = 'Edit';
    $handler->display->display_options['fields']['edit_node']['alter']['alter_text'] = 0;
    $handler->display->display_options['fields']['edit_node']['alter']['make_link'] = 0;
    $handler->display->display_options['fields']['edit_node']['alter']['absolute'] = 0;
    $handler->display->display_options['fields']['edit_node']['alter']['replace_spaces'] = 0;
    $handler->display->display_options['fields']['edit_node']['alter']['trim_whitespace'] = 0;
    $handler->display->display_options['fields']['edit_node']['alter']['nl2br'] = 0;
    $handler->display->display_options['fields']['edit_node']['alter']['word_boundary'] = 1;
    $handler->display->display_options['fields']['edit_node']['alter']['ellipsis'] = 1;
    $handler->display->display_options['fields']['edit_node']['alter']['more_link'] = 0;
    $handler->display->display_options['fields']['edit_node']['alter']['strip_tags'] = 0;
    $handler->display->display_options['fields']['edit_node']['alter']['trim'] = 0;
    $handler->display->display_options['fields']['edit_node']['alter']['html'] = 0;
    $handler->display->display_options['fields']['edit_node']['element_label_colon'] = 1;
    $handler->display->display_options['fields']['edit_node']['element_default_classes'] = 1;
    $handler->display->display_options['fields']['edit_node']['hide_empty'] = 0;
    $handler->display->display_options['fields']['edit_node']['empty_zero'] = 0;
    $handler->display->display_options['fields']['edit_node']['hide_alter_empty'] = 1;
    $handler->display->display_options['fields']['delete_node']['id'] = 'delete_node';
    $handler->display->display_options['fields']['delete_node']['table'] = 'views_entity_node';
    $handler->display->display_options['fields']['delete_node']['field'] = 'delete_node';
    $handler->display->display_options['fields']['delete_node']['label'] = 'Delete';
    $handler->display->display_options['fields']['delete_node']['alter']['alter_text'] = 0;
    $handler->display->display_options['fields']['delete_node']['alter']['make_link'] = 0;
    $handler->display->display_options['fields']['delete_node']['alter']['absolute'] = 0;
    $handler->display->display_options['fields']['delete_node']['alter']['replace_spaces'] = 0;
    $handler->display->display_options['fields']['delete_node']['alter']['trim_whitespace'] = 0;
    $handler->display->display_options['fields']['delete_node']['alter']['nl2br'] = 0;
    $handler->display->display_options['fields']['delete_node']['alter']['word_boundary'] = 1;
    $handler->display->display_options['fields']['delete_node']['alter']['ellipsis'] = 1;
    $handler->display->display_options['fields']['delete_node']['alter']['more_link'] = 0;
    $handler->display->display_options['fields']['delete_node']['alter']['strip_tags'] = 0;
    $handler->display->display_options['fields']['delete_node']['alter']['trim'] = 0;
    $handler->display->display_options['fields']['delete_node']['alter']['html'] = 0;
    $handler->display->display_options['fields']['delete_node']['element_label_colon'] = 1;
    $handler->display->display_options['fields']['delete_node']['element_default_classes'] = 1;
    $handler->display->display_options['fields']['delete_node']['hide_empty'] = 0;
    $handler->display->display_options['fields']['delete_node']['empty_zero'] = 0;
    $handler->display->display_options['fields']['delete_node']['hide_alter_empty'] = 1;

    $handler->display->display_options['filters']['type']['id'] = 'type';
    $handler->display->display_options['filters']['type']['table'] = 'node';
    $handler->display->display_options['filters']['type']['field'] = 'type';
    $handler->display->display_options['filters']['type']['value'] = array(
      $content_type => $content_type,
    );

    $handler->display->display_options['filters']['status']['id'] = 'status';
    $handler->display->display_options['filters']['status']['table'] = 'node';
    $handler->display->display_options['filters']['status']['field'] = 'status';
    $handler->display->display_options['filters']['status']['value'] = '1';
    $handler->display->display_options['filters']['status']['exposed'] = TRUE;
    $handler->display->display_options['filters']['status']['expose']['operator_id'] = '';
    $handler->display->display_options['filters']['status']['expose']['label'] = 'Published';
    $handler->display->display_options['filters']['status']['expose']['operator'] = 'status_op';
    $handler->display->display_options['filters']['status']['expose']['identifier'] = 'status';
    $handler->display->display_options['filters']['status']['expose']['required'] = TRUE;

    if ($has_languages) {
      $handler->display->display_options['filters']['language']['id'] = 'language';
      $handler->display->display_options['filters']['language']['table'] = 'node';
      $handler->display->display_options['filters']['language']['field'] = 'language';
      $handler->display->display_options['filters']['language']['exposed'] = TRUE;
      $handler->display->display_options['filters']['language']['expose']['operator_id'] = 'language_op';
      $handler->display->display_options['filters']['language']['expose']['label'] = 'Language';
      $handler->display->display_options['filters']['language']['expose']['operator'] = 'language_op';
      $handler->display->display_options['filters']['language']['expose']['identifier'] = 'language';
    }

    $handler = $view->new_display('page', 'Page', 'page');
    $handler->display->display_options['path'] = 'admin/fast-admin/node/' . $path_name;
    $handler->display->display_options['menu']['type'] = 'normal';
    $handler->display->display_options['menu']['title'] = 'Admin ' . $content_type_obj->name;
    $handler->display->display_options['menu']['description'] = 'Admin ' . $content_type_obj->name;
    $handler->display->display_options['menu']['weight'] = $weight++;
    $handler->display->display_options['menu']['name'] = 'fast_admin';
    $handler->display->display_options['menu']['context'] = 0;


    $views[$view->name] = $view;

  }

  // TO-DO: Any kind of entity!!

  return $views;

}
