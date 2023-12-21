/*
 * Last changed at upstream commit 790bc8d6ece1bf5f739debaa4aa4af508982070a
 * https://github.com/espressif/esp-zigbee-sdk/commit/790bc8d6ece1bf5f739debaa4aa4af508982070a
 * Upstream date: 2023-12-21 19:52:25 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.0.7(bdde218a)
 * Source: libesp_zb_cli_command -> zb_esp_cli_cmd_bdb.o -> cmd_zb_nwkkey
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void cmd_zb_nwkkey(char *param_1)

{
  size_t sVar1;
  undefined4 uVar2;
  int iVar3;
  undefined1 uStack_20;
  undefined1 uStack_1f;
  undefined1 uStack_1e;
  
  sVar1 = strlen(param_1);
  if (m_stack_is_started == '\0') {
    if ((sVar1 & 0xff) == 0x20) {
      iVar3 = parse_hex_str(param_1,&uStack_20,0x10,0);
      if (iVar3 == 0) {
        uVar2 = esp_log_timestamp();
        esp_log_write(1,0x10000,&_LC40,uVar2,0x10000);
      }
      else {
        zb_secur_setup_nwk_key(&uStack_20,0);
        uVar2 = esp_log_timestamp();
        esp_log_write(3,0x10000,&_LC39,uVar2,0x10000,uStack_20,uStack_1f,uStack_1e);
        uVar2 = esp_log_timestamp();
        esp_log_write(3,0x10000,&_LC4,uVar2,0x10000);
      }
    }
    else {
      uVar2 = esp_log_timestamp();
      esp_log_write(1,0x10000,&_LC34,uVar2,0x10000);
    }
  }
  else {
    uVar2 = esp_log_timestamp();
    esp_log_write(1,0x10000,&_LC19,uVar2,0x10000);
  }
  return;
}

