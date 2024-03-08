/*
 * Last changed at upstream commit 2fe15bae2e4382ac99f249a0934066f5d5a5c684
 * https://github.com/espressif/esp-zigbee-sdk/commit/2fe15bae2e4382ac99f249a0934066f5d5a5c684
 * Upstream date: 2024-03-08 17:10:04 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.2.0(9d7e9ff2)
 * Source: libesp_zb_cli_command -> zb_esp_cli_cmd_zdo.o -> ctx_timeout_cb
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void ctx_timeout_cb(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = get_ctx_by_tsn();
  if (iVar1 == 0) {
    uVar2 = esp_log_timestamp();
    esp_log_write(1,&_LC3,&_L0,uVar2,&_LC3,param_1);
  }
  else {
    uVar2 = esp_log_timestamp();
    esp_log_write(1,&_LC3,&_LC13,uVar2,&_LC3,param_1);
    invalidate_ctx(iVar1);
  }
  return;
}

