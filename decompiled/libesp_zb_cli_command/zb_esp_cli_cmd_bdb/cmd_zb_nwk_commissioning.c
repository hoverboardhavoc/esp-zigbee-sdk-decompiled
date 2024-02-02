/*
 * Last changed at upstream commit f9cc2dccd1062ffdf8f9e034d227fe83c0a1712e
 * https://github.com/espressif/esp-zigbee-sdk/commit/f9cc2dccd1062ffdf8f9e034d227fe83c0a1712e
 * Upstream date: 2024-02-02 22:17:34 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.1.0(5362d771)
 * Source: libesp_zb_cli_command -> zb_esp_cli_cmd_bdb.o -> cmd_zb_nwk_commissioning
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void cmd_zb_nwk_commissioning(char *param_1)

{
  undefined4 uVar1;
  undefined1 uVar2;
  int iVar3;
  
  if (param_1 == (char *)0x0) {
    uVar1 = esp_log_timestamp();
    esp_log_write(1,0x10000,&_LC8,uVar1,0x10000,"cmd_zb_nwk_commissioning",0x160);
  }
  else {
    iVar3 = strcmp(param_1,"help");
    if (iVar3 == 0) {
      uVar1 = esp_log_timestamp();
      esp_log_write(3,0x10000,&_LC28,uVar1,0x10000);
      done_or_failed(0);
    }
    else if (m_stack_is_started == '\0') {
      uVar1 = esp_log_timestamp();
      esp_log_write(1,0x10000,&_LC37,uVar1,0x10000);
      done_or_failed(0);
    }
    else {
      iVar3 = strcmp(param_1,"get");
      if (iVar3 == 0) {
        uVar1 = esp_log_timestamp();
        esp_log_write(3,0x10000,&_LC29,uVar1,0x10000,DAT_000150b7);
        uVar1 = 0;
      }
      else {
        iVar3 = strcmp(param_1,"init");
        if (iVar3 == 0) {
          iVar3 = bdb_start_top_level_commissioning(0);
          uVar1 = 0;
          if (iVar3 == 0) {
            uVar1 = 0xffffffff;
          }
        }
        else {
          iVar3 = strcmp(param_1,"steering");
          if (iVar3 == 0) {
            if (m_is_distributed != '\0') {
              zb_enable_joining_to_distributed(1);
            }
            iVar3 = bdb_start_top_level_commissioning(2);
            uVar1 = 0;
            if (iVar3 == 0) {
              uVar1 = 0xffffffff;
            }
          }
          else {
            iVar3 = strcmp(param_1,"form");
            if (iVar3 == 0) {
              if (m_is_distributed != '\0') {
                zb_enable_distributed();
                zb_zdo_setup_network_as_distributed();
                zb_aib_tcpol_set_is_distributed_security(1);
              }
              iVar3 = bdb_start_top_level_commissioning(4);
              uVar1 = 0;
              if (iVar3 == 0) {
                uVar1 = 0xffffffff;
              }
            }
            else {
              iVar3 = strcmp(param_1,"binding");
              if (iVar3 == 0) {
                iVar3 = bdb_start_top_level_commissioning(8);
                uVar1 = 0;
                if (iVar3 == 0) {
                  uVar1 = 0xffffffff;
                }
              }
              else {
                iVar3 = strcmp(param_1,"initiator");
                if (iVar3 == 0) {
                  zb_get_bdb_primary_channel_set();
                  uVar2 = __ctzsi2();
                  zb_zdo_touchlink_set_nwk_channel(uVar2);
                  iVar3 = bdb_start_top_level_commissioning(1);
                  uVar1 = 0;
                  if (iVar3 == 0) {
                    uVar1 = 0xffffffff;
                  }
                }
                else {
                  iVar3 = strcmp(param_1,"target");
                  if (iVar3 == 0) {
                    zb_get_bdb_primary_channel_set();
                    zb_set_channel_mask();
                    iVar3 = bdb_start_top_level_commissioning(0x40);
                    uVar1 = 0;
                    if (iVar3 == 0) {
                      uVar1 = 0xffffffff;
                    }
                  }
                  else {
                    uVar1 = esp_log_timestamp();
                    esp_log_write(1,0x10000,&_LC36,uVar1,0x10000);
                    uVar1 = 0;
                  }
                }
              }
            }
          }
        }
      }
      done_or_failed(uVar1);
    }
  }
  return;
}

