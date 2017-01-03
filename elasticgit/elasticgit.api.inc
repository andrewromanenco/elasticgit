<?php

$GLOBALS['EG_USER_REPO_LIMIT'] = 20;
$GLOBALS['KEY_FINGERPRINT_SCRIPT'] = '/Applications/MAMP/htdocs/elasticgit/perlscripts/key-fingerprint.pl';
$GLOBALS['KEY_GENERATE_SCRIPT'] = '/Applications/MAMP/htdocs/elasticgit/perlscripts/key-generate.pl';
$GLOBALS['PATH_KEY_DIR'] = '';

/*
 * true/false
 */
function api_createspace($name) {
	//watchdog('elastic', 'Can not create space: %name', array('%name' => $name), WATCHDOG_ERROR);
	watchdog('elastic', 'Created space: %name', array('%name' => $name), WATCHDOG_INFO);
	return true;
}

function api_createrepo($space, $name) {
	//watchdog('elastic', 'Can not create repo: %name in space: %space', array('%name' => $name, '%space' => $space), WATCHDOG_ERROR);
	watchdog('elastic', 'Created repo: %name in space: %space', array('%name' => $name, '%space' => $space), WATCHDOG_INFO);
	return true;
}

function api_droprepo($space, $name) {
	//watchdog('elastic', 'Can not drop repo: %name for space: %space', array('%name' => $name, '%space' => $space), WATCHDOG_ERROR);
	watchdog('elastic', 'Drop repo: %name for space: %space', array('%name' => $name, '%space' => $space), WATCHDOG_INFO);
	return true;
}

?>