/*
 * Last changed at upstream commit 55d58f0243c7dca5c0887a2b065178dacc2d00be
 * https://github.com/espressif/esp-zigbee-sdk/commit/55d58f0243c7dca5c0887a2b065178dacc2d00be
 * Upstream date: 2022-11-15 14:25:21 +0800
 * Upstream subject: cli: Add cli example
 * Source: libesp_zb_cli_command -> zb_esp_cli_cmd_zdo.o -> print_bind_resp
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void print_bind_resp(int param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = (uint)*(byte *)(param_1 + 3);
  uVar2 = *(byte *)(param_1 + 4) + uVar1;
  param_1 = param_1 + 5;
  for (; uVar1 < uVar2; uVar1 = uVar1 + 1) {
    print_bind_resp_record(uVar1,param_1);
    param_1 = param_1 + 0x15;
  }
  return;
}

