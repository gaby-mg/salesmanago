<?php
/**
 * @file
 * salesmanago.features.inc
 */

/**
 * Implements hook_default_wsclient_service().
 */
function salesmanago_default_wsclient_service() {
  $items = array();
  $items['salesmanago'] = entity_import('wsclient_service', '{
    "settings" : {
      "authentication" : {
        "type" : "none",
        "basic" : { "username" : "", "password" : "" },
        "wss" : { "username" : "", "password" : "" },
        "oauth2" : {
          "auth_flow" : "client-credentials",
          "token_endpoint" : "",
          "client_id" : "",
          "client_secret" : "",
          "scope" : "",
          "query_auth" : "0",
          "redirect_uri" : "",
          "authorization_endpoint" : "",
          "username" : "",
          "password" : ""
        }
      },
      "send_formatter" : {
        "class" : "WsclientRestJSONFormatter",
        "settings" : { "default_root" : "result", "adaptive_root" : 0 }
      },
      "receive_formatter" : {
        "class" : "WsclientRestJSONFormatter",
        "settings" : { "default_root" : "result", "adaptive_root" : 0 }
      }
    },
    "operations" : { "salesmanago_contact_upsert" : {
        "url" : "\\/contact\\/upsert",
        "label" : "Update Contact",
        "type" : "POST",
        "parameter" : {
          "contact" : { "type" : "salesmanago_contact" },
          "apiKey" : { "type" : "text", "default value" : "y3jvf6dla63hovcx3" },
          "clientId" : { "type" : "text", "default value" : "vyv0l0g7bnck59rb" },
          "requestTime" : { "type" : "date" },
          "sha" : {
            "type" : "text",
            "default value" : "1af756186e7afc3f0ccd49d3c7a2801e9ce1c70d"
          },
          "owner" : { "type" : "text", "default value" : "alvaro@winnya.com" }
        },
        "name" : "salesmanago_contact_upsert",
        "result" : {
          "type" : "salesmanago_contact_response",
          "label" : "SalesManago Contact Update Response"
        }
      }
    },
    "datatypes" : {
      "salesmanago_contact" : {
        "label" : "SalesManago Contact",
        "property info" : { "email" : { "type" : "text", "label" : "email" } }
      },
      "salesmanago_contact_response" : {
        "label" : "SalesManago Contact Response",
        "property info" : {
          "success" : { "type" : "boolean", "label" : "Success" },
          "contactId" : { "type" : "text", "label" : "Contact ID" }
        },
        "name" : "salesmanago_contact_response"
      }
    },
    "global_parameters" : [],
    "global_header_parameters" : [],
    "name" : "salesmanago",
    "label" : "SalesManago",
    "url" : "http:\\/\\/www.salesmanago.pl\\/api",
    "type" : "rest",
    "authentication" : null,
    "rdf_mapping" : []
  }');
  return $items;
}
