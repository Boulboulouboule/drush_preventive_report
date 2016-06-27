<?php

/**
 * Implements hook_drush_command().
 */
function drush_preventive_report_drush_command(){
  $items['drush-preventive-report'] = array(
    'description' => 'Make a preventive report for the drupal current installation',
    'aliases' => array('pr', 'report')
  );

  return $items;
}

/*
 * The drush callback
 */
function drush_drush_preventive_report(){
  drush_active_modules(array('update', 'devel', 'hacked'));
  drush_check_security_updates();
  drush_check_standard_updates();
  drush_check_hacked_modules_updates();
  drush_create_report();
}
