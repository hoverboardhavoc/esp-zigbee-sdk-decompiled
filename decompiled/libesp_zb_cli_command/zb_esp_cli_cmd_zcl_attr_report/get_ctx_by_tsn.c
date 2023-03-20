/*
 * Last changed at upstream commit 8f416d47159477fb2dfe72f817700bc25debb587
 * https://github.com/espressif/esp-zigbee-sdk/commit/8f416d47159477fb2dfe72f817700bc25debb587
 * Upstream date: 2023-03-20 14:23:27 +0800
 * Upstream subject: zcl: support more ZCL cluster(caef391)
 * Source: libesp_zb_cli_command -> zb_esp_cli_cmd_zcl_attr_report.o -> get_ctx_by_tsn
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined1 * get_ctx_by_tsn(uint param_1)

{
  uint uVar1;
  
  uVar1 = 0;
  while( true ) {
    if (2 < uVar1) {
      return (undefined1 *)0x0;
    }
    if (((&DAT_00011229)[uVar1 * 3] != '\0') && ((byte)(&m_tsn_ctx)[uVar1 * 3] == param_1)) break;
    uVar1 = uVar1 + 1 & 0xff;
  }
  return &m_tsn_ctx + uVar1 * 3;
}

