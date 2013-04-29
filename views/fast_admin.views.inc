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

    $view = new view;
    $view->name = 'fast_admin__' . $content_type;
    $view->description = '';
    $view->tag = 'fast_admin';
    $view->base_table = 'node';
    $view->human_name = 'Fast admin: ' . $content_type_obj->name;
    $view->core = 0;
    $view->api_version = '3.0';
    $view->disabled = FALSE;

    $handler = $view->new_display('default', 'Master', 'default');
    $handler->display->display_options['use_ajax'] = TRUE;
    $handler->display->display_options['access']['type'] = 'none'; // TO-DO: Permission!
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
    $handler->display->display_options['fields']['status']['id'] = 'status';
    $handler->display->display_options['fields']['status']['table'] = 'node';
    $handler->display->display_options['fields']['status']['field'] = 'status';
    $handler->display->display_options['fields']['status']['label'] = 'Status';
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
    $handler->display->display_options['fields']['title']['hide_empty'] = 0;
    $handler->display->display_options['fields']['title']['empty_zero'] = 0;
    $handler->display->display_options['fields']['title']['link_to_node'] = 1;
    $handler->display->display_options['filters']['type']['id'] = 'type';
    $handler->display->display_options['filters']['type']['table'] = 'node';
    $handler->display->display_options['filters']['type']['field'] = 'type';
    $handler->display->display_options['filters']['type']['value'] = array(
      $content_type => $content_type,
    );

    $handler->display->display_options['header']['area']['id'] = 'area';
    $handler->display->display_options['header']['area']['table'] = 'views';
    $handler->display->display_options['header']['area']['field'] = 'area';
    $handler->display->display_options['header']['area']['label'] = 'Link to new ' . $content_type_obj->name;
    $handler->display->display_options['header']['area']['empty'] = TRUE;

    $path_name = str_replace('_', '-', $content_type);

    // TO-DO: Links handler areas 
    if(false)){
      // TO-DO: User access crete permission
      $handler->display->display_options['header']['area']['content'] = '<ul class="action-links clearfix"><li><a href="/node/add/' . $path_name . '?destination=admin/fast-admin/' . $path_name . '"><?php print t("Add !type", array("!type" => t(' . $content_type_obj->name . '))); ?></a></li></ul>';
      $handler->display->display_options['header']['area']['format'] = 'php_code';
    }
    else{
      $handler->display->display_options['header']['area']['content'] = '<ul class="action-links clearfix"><li><a href="/node/add/' . $path_name . '?destination=admin/fast-admin/' . $path_name . '">' . t('Add !type', array('!type' => $content_type_obj->name)) . '</a></li></ul>';
      $handler->display->display_options['header']['area']['format'] = 'full_html';
    }

    $handler->display->display_options['filters']['status']['id'] = 'status';
    $handler->display->display_options['filters']['status']['table'] = 'node';
    $handler->display->display_options['filters']['status']['field'] = 'status';
    $handler->display->display_options['filters']['status']['value'] = '1';
    $handler->display->display_options['filters']['status']['exposed'] = TRUE;
    $handler->display->display_options['filters']['status']['expose']['operator_id'] = '';
    $handler->display->display_options['filters']['status']['expose']['label'] = 'Publicado';
    $handler->display->display_options['filters']['status']['expose']['operator'] = 'status_op';
    $handler->display->display_options['filters']['status']['expose']['identifier'] = 'status';
    $handler->display->display_options['filters']['status']['expose']['required'] = TRUE;

    $handler = $view->new_display('page', 'Page', 'page');
    $handler->display->display_options['path'] = 'admin/fast-admin/' . $path_name;
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
