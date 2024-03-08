/*
 * Last changed at upstream commit 2fe15bae2e4382ac99f249a0934066f5d5a5c684
 * https://github.com/espressif/esp-zigbee-sdk/commit/2fe15bae2e4382ac99f249a0934066f5d5a5c684
 * Upstream date: 2024-03-08 17:10:04 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.2.0(9d7e9ff2)
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
        esp_log_write(1,0x10000,&_LC88,uVar2,0x10000);
      }
      else {
        zb_secur_setup_nwk_key(&uStack_20,0);
        uVar2 = esp_log_timestamp();
        esp_log_write(3,0x10000,&_LC87,uVar2,0x10000,uStack_20,uStack_1f,uStack_1e);
        uVar2 = esp_log_timestamp();
        esp_log_write(3,0x10000,&_LC7,uVar2,0x10000);
      }
    }
    else {
      uVar2 = esp_log_timestamp();
      esp_log_write(1,0x10000,&_LC82,uVar2,0x10000);
    }
  }
  else {
    uVar2 = esp_log_timestamp();
    esp_log_write(1,0x10000,&_LC19,uVar2,0x10000);
  }
  return;
}

