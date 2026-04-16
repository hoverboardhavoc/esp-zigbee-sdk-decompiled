/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> zcl_general_cmd.o -> check_write_attr_filed
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

zcl_status_t check_write_attr_filed(zcl_write_attr_req_t *req,zcl_attr_desc_t *attr_desc)

{
  byte bVar1;
  
  if (attr_desc == (zcl_attr_desc_t *)0x0) {
    return 0x86;
  }
  if (attr_desc->type != req->attr_type) {
    return 0x8d;
  }
  bVar1 = attr_desc->access;
  if (bVar1 == 1) {
    return 0x88;
  }
  if ((bVar1 & 2) != 0) {
    if ((bVar1 & 0x40) == 0) {
      return bVar1 & 0x40;
    }
    return 0x86;
  }
  return 0x88;
}

