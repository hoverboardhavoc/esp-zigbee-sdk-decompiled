/*
 * Last changed at upstream commit f9cc2dccd1062ffdf8f9e034d227fe83c0a1712e
 * https://github.com/espressif/esp-zigbee-sdk/commit/f9cc2dccd1062ffdf8f9e034d227fe83c0a1712e
 * Upstream date: 2024-02-02 22:17:34 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.1.0(5362d771)
 * Source: libesp_zb_cli_command -> zb_esp_cli_cmd_bdb.o -> cmd_zb_legacy
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void cmd_zb_legacy(char *param_1)

{
  size_t sVar1;
  int iVar2;
  undefined4 uVar3;
  undefined *puVar4;
  
  sVar1 = strlen(param_1);
  if (m_stack_is_started == '\0') {
    uVar3 = esp_log_timestamp();
    esp_log_write(1,0x10000,&_LC69,uVar3,0x10000);
  }
  else {
    iVar2 = strcmp(param_1,"get");
    if (iVar2 == 0) {
      uVar3 = esp_log_timestamp();
      if (m_legacy_mode == '\0') {
        puVar4 = &_LC78;
      }
      else {
        puVar4 = &_LC77;
      }
      esp_log_write(3,0x10000,&_LC48,uVar3,0x10000,puVar4);
    }
    else if (((sVar1 & 0xff) - 6 & 0xff) < 2) {
      iVar2 = strcmp(param_1,"enable");
      if (iVar2 == 0) {
        zb_bdb_set_legacy_device_support(1);
        m_legacy_mode = '\x01';
        uVar3 = esp_log_timestamp();
        esp_log_write(3,0x10000,&_LC1,uVar3,0x10000);
      }
      else {
        iVar2 = strcmp(param_1,"disable");
        if (iVar2 == 0) {
          zb_bdb_set_legacy_device_support();
          m_legacy_mode = '\0';
          uVar3 = esp_log_timestamp();
          esp_log_write(3,0x10000,&_LC1,uVar3,0x10000);
        }
        else {
          uVar3 = esp_log_timestamp();
          esp_log_write(1,0x10000,&_LC79,uVar3,0x10000);
        }
      }
    }
    else {
      uVar3 = esp_log_timestamp();
      esp_log_write(1,0x10000,&_LC80,uVar3,0x10000);
    }
  }
  return;
}

