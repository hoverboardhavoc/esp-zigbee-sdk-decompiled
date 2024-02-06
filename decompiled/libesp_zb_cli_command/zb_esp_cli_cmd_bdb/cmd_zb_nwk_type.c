/*
 * Last changed at upstream commit d7e241034cb0adc2116988a320badb285c391de3
 * https://github.com/espressif/esp-zigbee-sdk/commit/d7e241034cb0adc2116988a320badb285c391de3
 * Upstream date: 2024-02-06 17:30:29 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.1.1(0cd72dc5)
 * Source: libesp_zb_cli_command -> zb_esp_cli_cmd_bdb.o -> cmd_zb_nwk_type
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void cmd_zb_nwk_type(char *param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined *puVar3;
  char *pcVar4;
  
  if (param_1 == (char *)0x0) {
    uVar2 = esp_log_timestamp();
    esp_log_write(1,0x10000,&_LC8,uVar2,0x10000,"cmd_zb_nwk_type",0xc9);
  }
  else {
    iVar1 = strcmp(param_1,"help");
    if (iVar1 == 0) {
      uVar2 = esp_log_timestamp();
      esp_log_write(3,0x10000,&_LC10,uVar2,0x10000);
      done_or_failed(0);
    }
    else {
      iVar1 = strcmp(param_1,"get");
      if (iVar1 == 0) {
        uVar2 = esp_log_timestamp();
        if (m_is_distributed == '\0') {
          pcVar4 = "Centralized";
        }
        else {
          pcVar4 = "Distributed";
        }
        esp_log_write(3,0x10000,&_LC12,uVar2,0x10000,pcVar4);
        uVar2 = 0;
      }
      else {
        if (m_stack_is_started != '\0') {
          uVar2 = esp_log_timestamp();
          esp_log_write(1,0x10000,&_LC13,uVar2,0x10000);
          done_or_failed(0);
          return;
        }
        iVar1 = strcmp(param_1,"c");
        if (iVar1 == 0) {
          uVar2 = esp_log_timestamp();
          esp_log_write(3,0x10000,&_LC15,uVar2,0x10000);
          m_is_distributed = '\0';
          uVar2 = 0;
        }
        else {
          iVar1 = strcmp(param_1,"d");
          if (iVar1 == 0) {
            if (m_default_role == '\x01') {
              uVar2 = esp_log_timestamp();
              esp_log_write(3,0x10000,&_LC18,uVar2,0x10000);
              m_is_distributed = '\x01';
              uVar2 = 0;
            }
            else {
              uVar2 = esp_log_timestamp();
              if (m_default_role == '\0') {
                puVar3 = &_LC6;
              }
              else if (m_default_role == '\x02') {
                puVar3 = &_LC7;
              }
              else {
                puVar3 = &_LC5;
              }
              esp_log_write(1,0x10000,&_LC17,uVar2,0x10000,puVar3);
              uVar2 = 0xffffffff;
            }
          }
          else {
            uVar2 = esp_log_timestamp();
            esp_log_write(1,0x10000,&_LC19,uVar2,0x10000);
            uVar2 = 0xffffffff;
          }
        }
      }
      done_or_failed(uVar2);
    }
  }
  return;
}

