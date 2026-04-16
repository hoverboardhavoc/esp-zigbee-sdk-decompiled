/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> zcl_desc.o -> check_attr_is_unique
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

_Bool check_attr_is_unique(zcl_attr_desc_t *head,uint16_t attr_id,uint16_t manuf_code)

{
  undefined2 in_register_0000202e;
  undefined2 in_register_00002032;
  
  while( true ) {
    if (head == (zcl_attr_desc_t *)0x0) {
      return true;
    }
    if (((uint)head->id == CONCAT22(in_register_0000202e,attr_id)) &&
       ((uint)head->manuf_code == CONCAT22(in_register_00002032,manuf_code))) break;
    head = head->next;
  }
  return false;
}

