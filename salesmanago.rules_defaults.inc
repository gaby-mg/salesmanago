<?php
/**
 * @file
 * salesmanago.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function salesmanago_default_rules_configuration() {
  $items = array();
  $items['rules_wv_salesmanago_upsert'] = entity_import('rules_config', '{ "rules_wv_salesmanago_upsert" : {
      "LABEL" : "Update SalesManago Contact",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "Commerce Checkout", "SalesManago", "World Vision" ],
      "REQUIRES" : [ "rules", "wsclient", "cookie_monster", "commerce_checkout" ],
      "ON" : { "commerce_checkout_complete" : [] },
      "DO" : [
        { "data_create" : {
            "USING" : {
              "type" : "wsclient_salesmanago_salesmanago_contact",
              "param_email" : [ "commerce-order:mail" ]
            },
            "PROVIDE" : { "data_created" : { "created_contact" : "Created Contact" } }
          }
        },
        { "wsclient_salesmanago_salesmanago_contact_upsert" : {
            "USING" : {
              "param_contact" : [ "created-contact" ],
              "param_apiKey" : "y3jvf6dla63hovcx3",
              "param_clientId" : "vyv0l0g7bnck59rb",
              "param_requestTime" : 1489431788,
              "param_sha" : "1af756186e7afc3f0ccd49d3c7a2801e9ce1c70d",
              "param_owner" : "alvaro@winnya.com"
            },
            "PROVIDE" : { "result" : { "result" : "SalesManago Contact Update Response" } }
          }
        },
        { "cookie_monster_rules_set_cookie" : { "cookie_id" : "smclient", "cookie_data" : [ "result:contactId" ] } }
      ]
    }
  }');
  return $items;
}
