/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> zcl_general_cmd.o -> check_configure_reporting_field
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

zcl_status_t
check_configure_reporting_field(zcl_configure_reporting_req_t *req,zcl_attr_desc_t *attr_desc)

{
  ushort uVar1;
  uint uVar2;
  
  if (req == (zcl_configure_reporting_req_t *)0x0) {
    return '\x01';
  }
  if (req->direction == '\0') {
    if (attr_desc == (zcl_attr_desc_t *)0x0) {
      return 0x86;
    }
    if (attr_desc->data_p == (void *)0x0) {
      return 0x86;
    }
    uVar2 = attr_desc->type - 0x48;
    if (((uVar2 & 0xff) < 10) && ((0x317U >> (uVar2 & 0x1f) & 1) != 0)) {
      return 0x8c;
    }
    if ((attr_desc->access & 4) == 0) {
      return 0x8c;
    }
    if ((uint)attr_desc->type != (uint)(req->field_2).send_info.attr_type) {
      return 0x8d;
    }
    uVar1 = (req->field_2).send_info.max_reporting_interval;
    if ((uVar1 != 0) && (uVar1 < (req->field_2).send_info.min_reporting_interval)) {
      return 0x87;
    }
  }
  else if (attr_desc == (zcl_attr_desc_t *)0x0) {
    return 0x8c;
  }
  return '\0';
}

