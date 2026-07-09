/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee.debug -> zcl_core_compat.o -> zcl_core_action_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void zcl_core_action_handler(uint param_1,undefined4 param_2)

{
  if (param_1 == 0x1a) {
    zb_zcl_door_lock_lock_door_resp_handler(param_2,s_core_action,1);
  }
  else if (param_1 < 0x1b) {
    if (param_1 == 0xf) {
      zb_zcl_groups_view_group_resp_handler(s_core_action);
    }
    else if (param_1 < 0x10) {
      if (param_1 == 5) {
        zb_zcl_report_attr_handler(s_core_action);
      }
      else if (param_1 < 6) {
        if (param_1 == 2) {
          zb_zcl_write_attr_resp_handler(s_core_action);
        }
        else if (param_1 < 3) {
          if (param_1 == 0) {
            zb_zcl_set_attr_value_handler(s_core_action);
          }
          else if (param_1 == 1) {
            zb_zcl_read_attr_resp_handler(s_core_action);
          }
        }
        else if (param_1 == 3) {
          zb_zcl_config_report_resp_handler(s_core_action);
        }
        else if (param_1 == 4) {
          zb_zcl_read_report_config_resp_handler(s_core_action);
        }
      }
      else if (param_1 == 0xb) {
        zb_zcl_identify_effect_handler(s_core_action);
      }
      else if (param_1 < 0xc) {
        if (param_1 == 6) {
          zb_zcl_disc_attr_resp_handler(s_core_action);
        }
        else if (param_1 == 8) {
          zb_zcl_default_resp_handler(s_core_action);
        }
      }
      else if (param_1 == 0xc) {
        zb_zcl_basic_reset_to_factory_default_handler(s_core_action);
      }
      else if (param_1 == 0xe) {
        zb_zcl_groups_add_group_resp_handler(s_core_action);
      }
    }
    else if (param_1 == 0x15) {
      zb_zcl_scenes_store_scene_handler(s_core_action);
    }
    else if (param_1 < 0x16) {
      if (param_1 == 0x12) {
        zb_zcl_scenes_operate_scene_resp_handler(s_core_action);
      }
      else if (param_1 < 0x13) {
        if (param_1 == 0x10) {
          zb_zcl_groups_get_group_membership_resp_handler(s_core_action);
        }
        else if (param_1 == 0x11) {
          zb_zcl_groups_remove_group_resp_handler(s_core_action);
        }
      }
      else if (param_1 == 0x13) {
        zb_zcl_scenes_view_scene_resp_handler(s_core_action);
      }
      else if (param_1 == 0x14) {
        zb_zcl_scenes_get_scene_membership_resp_handler(s_core_action);
      }
    }
    else if (param_1 == 0x18) {
      zb_zcl_door_lock_lock_door_handler(s_core_action,1);
    }
    else if (param_1 < 0x19) {
      if (param_1 == 0x16) {
        zb_zcl_scenes_recall_scene_handler(s_core_action);
      }
      else if (param_1 == 0x17) {
        zb_zcl_door_lock_lock_door_handler(s_core_action,0);
      }
    }
    else if (param_1 == 0x19) {
      zb_zcl_door_lock_lock_door_resp_handler(s_core_action,0);
    }
  }
  else if (param_1 == 0x46) {
    zb_zcl_metering_request_fast_poll_mode_resp_handler(s_core_action);
  }
  else if (param_1 < 0x47) {
    if (param_1 == 0x38) {
      zb_zcl_thermostat_value_handler(s_core_action);
    }
    else if (param_1 < 0x39) {
      if (param_1 == 0x35) {
        zb_zcl_alarms_get_alarm_resp_handler(s_core_action);
      }
      else if (param_1 < 0x36) {
        if (param_1 == 0x1b) {
          zb_zcl_window_covering_movement_handler(s_core_action);
        }
        else if (param_1 == 0x34) {
          zb_zcl_alarms_alarm_handler(s_core_action);
        }
      }
      else if (param_1 == 0x36) {
        zb_zcl_alarms_reset_alarm_handler(s_core_action);
      }
      else if (param_1 == 0x37) {
        zb_zcl_alarms_reset_all_alarms_handler(s_core_action);
      }
    }
    else if (param_1 == 0x43) {
      zb_zcl_metering_get_profile_handler(s_core_action);
    }
    else if (param_1 < 0x44) {
      if (param_1 == 0x39) {
        zb_zcl_thermostat_set_weekly_schedule_handler(s_core_action);
      }
      else if (param_1 == 0x3a) {
        zb_zcl_thermostat_get_weekly_schedule_resp_handler(s_core_action);
      }
    }
    else if (param_1 == 0x44) {
      zb_zcl_metering_get_profile_resp_handler(s_core_action);
    }
    else if (param_1 == 0x45) {
      zb_zcl_metering_request_fast_poll_mode_handler(s_core_action);
    }
  }
  else if (param_1 == 0x4c) {
    zb_zcl_price_get_scheduled_prices_handler(s_core_action);
  }
  else if (param_1 < 0x4d) {
    if (param_1 == 0x49) {
      zb_zcl_metering_get_sampled_data_handler(s_core_action);
    }
    else if (param_1 < 0x4a) {
      if (param_1 == 0x47) {
        zb_zcl_metering_get_snapshot_handler(s_core_action);
      }
      else if (param_1 == 0x48) {
        zb_zcl_metering_publish_snapshot_handler(s_core_action);
      }
    }
    else if (param_1 == 0x4a) {
      zb_zcl_metering_get_sampled_data_resp_handler(s_core_action);
    }
    else if (param_1 == 0x4b) {
      zb_zcl_price_get_current_price_handler(s_core_action);
    }
  }
  else if (param_1 == 0x4f) {
    zb_zcl_price_publish_price_handler(s_core_action);
  }
  else if (param_1 < 0x50) {
    if (param_1 == 0x4d) {
      zb_zcl_price_get_tier_labels_handler(s_core_action);
    }
    else if (param_1 == 0x4e) {
      zb_zcl_price_price_ack_handler(s_core_action);
    }
  }
  else if (param_1 == 0x50) {
    zb_zcl_price_publish_tier_labels_handler(s_core_action);
  }
  return;
}

