/*
 * Last changed at upstream commit 2fe15bae2e4382ac99f249a0934066f5d5a5c684
 * https://github.com/espressif/esp-zigbee-sdk/commit/2fe15bae2e4382ac99f249a0934066f5d5a5c684
 * Upstream date: 2024-03-08 17:10:04 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.2.0(9d7e9ff2)
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
    esp_log_write(1,0x10000,&_LC14,uVar2,0x10000,"cmd_zb_nwk_type",0xd5);
  }
  else {
    iVar1 = strcmp(param_1,"help");
    if (iVar1 == 0) {
      uVar2 = esp_log_timestamp();
      esp_log_write(3,0x10000,&_LC16,uVar2,0x10000);
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
        esp_log_write(3,0x10000,&_LC18,uVar2,0x10000,pcVar4);
        uVar2 = 0;
      }
      else {
        if (m_stack_is_started != '\0') {
          uVar2 = esp_log_timestamp();
          esp_log_write(1,0x10000,&_LC19,uVar2,0x10000);
          done_or_failed(0);
          return;
        }
        iVar1 = strcmp(param_1,"c");
        if (iVar1 == 0) {
          uVar2 = esp_log_timestamp();
          esp_log_write(3,0x10000,&_LC21,uVar2,0x10000);
          m_is_distributed = '\0';
          uVar2 = 0;
        }
        else {
          iVar1 = strcmp(param_1,"d");
          if (iVar1 == 0) {
            if (m_default_role == '\x01') {
              uVar2 = esp_log_timestamp();
              esp_log_write(3,0x10000,&_LC24,uVar2,0x10000);
              m_is_distributed = '\x01';
              uVar2 = 0;
            }
            else {
              uVar2 = esp_log_timestamp();
              if (m_default_role == '\0') {
                puVar3 = &_LC12;
              }
              else if (m_default_role == '\x02') {
                puVar3 = &_LC13;
              }
              else {
                puVar3 = &_LC11;
              }
              esp_log_write(1,0x10000,&_LC23,uVar2,0x10000,puVar3);
              uVar2 = 0xffffffff;
            }
          }
          else {
            uVar2 = esp_log_timestamp();
            esp_log_write(1,0x10000,&_LC25,uVar2,0x10000);
            uVar2 = 0xffffffff;
          }
        }
      }
      done_or_failed(uVar2);
    }
  }
  return;
}

