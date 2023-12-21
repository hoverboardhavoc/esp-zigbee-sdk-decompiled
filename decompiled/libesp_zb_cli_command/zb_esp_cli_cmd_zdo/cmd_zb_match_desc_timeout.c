/*
 * Last changed at upstream commit 790bc8d6ece1bf5f739debaa4aa4af508982070a
 * https://github.com/espressif/esp-zigbee-sdk/commit/790bc8d6ece1bf5f739debaa4aa4af508982070a
 * Upstream date: 2023-12-21 19:52:25 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.0.7(bdde218a)
 * Source: libesp_zb_cli_command -> zb_esp_cli_cmd_zdo.o -> cmd_zb_match_desc_timeout
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void cmd_zb_match_desc_timeout(void)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = get_ctx_by_tsn();
  if (iVar1 != 0) {
    uVar2 = esp_log_timestamp();
    esp_log_write(3,&_LC0,&_LC4,uVar2,&_LC0);
    invalidate_ctx(iVar1);
  }
  return;
}

