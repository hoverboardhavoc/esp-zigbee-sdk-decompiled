/*
 * Last changed at upstream commit 55d58f0243c7dca5c0887a2b065178dacc2d00be
 * https://github.com/espressif/esp-zigbee-sdk/commit/55d58f0243c7dca5c0887a2b065178dacc2d00be
 * Upstream date: 2022-11-15 14:25:21 +0800
 * Upstream subject: cli: Add cli example
 * Source: libesp_zb_cli_command -> zb_esp_cli_cmd_zdo.o -> cmd_zb_ieee_addr_timeout
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void cmd_zb_ieee_addr_timeout(void)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = get_ctx_by_tsn();
  if (iVar1 != 0) {
    uVar2 = esp_log_timestamp();
    esp_log_write(1,&_LC3,&_LC5,uVar2,&_LC3);
    invalidate_ctx(iVar1);
  }
  return;
}

