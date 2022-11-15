/*
 * Last changed at upstream commit 55d58f0243c7dca5c0887a2b065178dacc2d00be
 * https://github.com/espressif/esp-zigbee-sdk/commit/55d58f0243c7dca5c0887a2b065178dacc2d00be
 * Upstream date: 2022-11-15 14:25:21 +0800
 * Upstream subject: cli: Add cli example
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
    esp_log_write(1,0x10000,&_LC31,uVar3,0x10000);
  }
  else {
    iVar2 = strcmp(param_1,"get");
    if (iVar2 == 0) {
      uVar3 = esp_log_timestamp();
      if (m_legacy_mode == '\0') {
        puVar4 = &_LC39;
      }
      else {
        puVar4 = &_LC38;
      }
      esp_log_write(3,0x10000,&_LC21,uVar3,0x10000,puVar4);
    }
    else if (((sVar1 & 0xff) - 6 & 0xff) < 2) {
      iVar2 = strcmp(param_1,"enable");
      if (iVar2 == 0) {
        zb_bdb_set_legacy_device_support(1);
        m_legacy_mode = '\x01';
        uVar3 = esp_log_timestamp();
        esp_log_write(3,0x10000,&_LC7,uVar3,0x10000);
      }
      else {
        iVar2 = strcmp(param_1,"disable");
        if (iVar2 == 0) {
          zb_bdb_set_legacy_device_support();
          m_legacy_mode = '\0';
          uVar3 = esp_log_timestamp();
          esp_log_write(3,0x10000,&_LC7,uVar3,0x10000);
        }
        else {
          uVar3 = esp_log_timestamp();
          esp_log_write(1,0x10000,&_LC40,uVar3,0x10000);
        }
      }
    }
    else {
      uVar3 = esp_log_timestamp();
      esp_log_write(1,0x10000,&_LC41,uVar3,0x10000);
    }
  }
  return;
}

