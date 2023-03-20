/*
 * Last changed at upstream commit 8f416d47159477fb2dfe72f817700bc25debb587
 * https://github.com/espressif/esp-zigbee-sdk/commit/8f416d47159477fb2dfe72f817700bc25debb587
 * Upstream date: 2023-03-20 14:23:27 +0800
 * Upstream subject: zcl: support more ZCL cluster(caef391)
 * Source: libesp_zb_cli_command -> zb_esp_cli_cmd_zdo.o -> sscan_cluster_list
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

bool sscan_cluster_list(int param_1,uint param_2,int param_3)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = 0;
  while ((uVar1 < param_2 &&
         (iVar2 = parse_hex_u16(*(undefined4 *)(uVar1 * 4 + param_1),param_3), iVar2 != 0))) {
    uVar1 = uVar1 + 1 & 0xffff;
    param_3 = param_3 + 2;
  }
  return param_2 == uVar1;
}

