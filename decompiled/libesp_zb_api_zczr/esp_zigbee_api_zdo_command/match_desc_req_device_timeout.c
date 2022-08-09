/*
 * Last changed at upstream commit 2941fbcc815001461b9ea708a1d755b07ce24ea3
 * https://github.com/espressif/esp-zigbee-sdk/commit/2941fbcc815001461b9ea708a1d755b07ce24ea3
 * Upstream date: 2022-08-09 20:36:03 +0800
 * Upstream subject: esp-zigbee-sdk: First sdk release
 * Source: libesp_zb_api_zczr -> esp_zigbee_api_zdo_command.o -> match_desc_req_device_timeout
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void match_desc_req_device_timeout(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = esp_log_timestamp();
  esp_log_write(3,0x10000,&_LC1,uVar1,0x10000);
  if (param_1 != 0) {
    zb_buf_free_func(param_1);
  }
  return;
}

