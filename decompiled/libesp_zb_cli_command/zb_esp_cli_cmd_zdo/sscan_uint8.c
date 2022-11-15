/*
 * Last changed at upstream commit 55d58f0243c7dca5c0887a2b065178dacc2d00be
 * https://github.com/espressif/esp-zigbee-sdk/commit/55d58f0243c7dca5c0887a2b065178dacc2d00be
 * Upstream date: 2022-11-15 14:25:21 +0800
 * Upstream subject: cli: Add cli example
 * Source: libesp_zb_cli_command -> zb_esp_cli_cmd_zdo.o -> sscan_uint8
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int sscan_uint8(char *param_1,undefined1 *param_2)

{
  int iVar1;
  uint uStack_14;
  
  iVar1 = sscanf(param_1,"%u");
  if (iVar1 != 0) {
    if (uStack_14 < 0x100) {
      *param_2 = (char)uStack_14;
      iVar1 = 1;
    }
    else {
      iVar1 = 0;
    }
  }
  return iVar1;
}

