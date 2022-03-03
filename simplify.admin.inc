<?php
/**
 * @file
 * Administrative page callbacks for the Simplify module.
 */

/**
 * Simplify global configuration form.
 */
function simplify_global_configuration_form($form, &$form_state) {
  $config = config('simplify.global');
  $form['#config'] = 'simplify.global';

  // Nodes.
  $form['nodes'] = array(
    '#type' => 'fieldset',
    '#title' => t('Nodes'),
    '#description' => t("These fields will be hidden from <em>all</em> node forms. Alternatively, to hide fields from node forms of a particular content type, edit the content type and configure the hidden fields there."),
  );
  $form['nodes']['nodes'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Hide:'),
    '#options' => simplify_get_fields('nodes'),
    '#default_value' => $config->get('nodes'),
  );

  // Users.
  $form['users'] = array(
    '#type' => 'fieldset',
    '#title' => t('Users'),
    '#description' => t("These fields will be hidden from all user account forms."),
  );
  $form['users']['users'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Hide:'),
    '#options' => simplify_get_fields('users'),
    '#default_value' => $config->get('users'),
  );

  // Comments.
  if (module_exists('comment')) {
    $form['comments'] = array(
      '#type' => 'fieldset',
      '#title' => t('Comments'),
      '#description' => t("These fields will be hidden from <em>all</em> comment forms. Alternatively, to hide fields from comment forms for nodes of a particular content type, edit the content type and configure the hidden fields there."),
    );
    $form['comments']['comments'] = array(
      '#type' => 'checkboxes',
      '#title' => t('Hide:'),
      '#options' => simplify_get_fields('comments'),
      '#default_value' => $config->get('comments'),
    );
  }

  // Taxonomy.
  if (module_exists('taxonomy')) {
    $form['taxonomy'] = array(
      '#type' => 'fieldset',
      '#title' => t('Taxonomy'),
      '#description' => t("These fields will be hidden from <em>all</em> taxonomy term forms. Alternatively, to hide fields from taxonomy term forms for a particular vocabulary, edit the vocabulary and configure the hidden fields there."),
    );
    $form['taxonomy']['taxonomy'] = array(
      '#type' => 'checkboxes',
      '#title' => t('Hide:'),
      '#options' => simplify_get_fields('taxonomy'),
      '#default_value' => $config->get('taxonomy'),
    );
  }

  // Blocks.
  if (module_exists('block')) {
    $form['blocks'] = array(
      '#type' => 'fieldset',
      '#title' => t('Blocks'),
      '#description' => t("These fields will be hidden from all block forms."),
    );
    $form['blocks']['blocks'] = array(
      '#type' => 'checkboxes',
      '#title' => t('Hide:'),
      '#options' => simplify_get_fields('blocks'),
      '#default_value' => $config->get('blocks'),
    );
  }

  // Advanced settings.
  $form['advanced'] = array(
    '#type' => 'fieldset',
    '#title' => t('Advanced settings'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  $form['advanced']['user1'] = array(
    '#type' => 'checkbox',
    '#title' => t('Hide fields from User 1'),
    '#description' => t("By default, Backdrop gives User 1 <em>all</em> permissions (including Simplify's <em>View hidden fields</em> permission). This means that User 1 will always be able to view all hidden fields (and is by design).<br>Check this box to override this functionality and hide fields from User 1. NOTE: As this option overrides default Backdrop behaviour, it should be used sparingly and only when you fully understand the consequences."),
    '#default_value' => $config->get('user1'),
  );

  return system_settings_form($form);
}
