/*
 * Last changed at upstream commit 55d58f0243c7dca5c0887a2b065178dacc2d00be
 * https://github.com/espressif/esp-zigbee-sdk/commit/55d58f0243c7dca5c0887a2b065178dacc2d00be
 * Upstream date: 2022-11-15 14:25:21 +0800
 * Upstream subject: cli: Add cli example
 * Source: libesp_zb_cli_command -> zb_esp_cli_cmd.o -> to_hex_str
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int to_hex_str(int param_1,int param_2,uint param_3)

{
  int iVar1;
  int iVar2;
  
  iVar1 = 0;
  while ((iVar2 = iVar1, param_3 != 0 &&
         (iVar2 = snprintf((char *)(param_1 + iVar1),param_2 - iVar1,"%02x"), -1 < iVar2))) {
    iVar1 = iVar1 + iVar2;
    param_3 = param_3 - 1 & 0xff;
  }
  return iVar2;
}

