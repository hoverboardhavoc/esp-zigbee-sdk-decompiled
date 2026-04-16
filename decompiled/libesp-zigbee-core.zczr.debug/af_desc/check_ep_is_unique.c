/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> af_desc.o -> check_ep_is_unique
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

_Bool check_ep_is_unique(af_ep_desc_t *head,uint8_t ep_id)

{
  undefined3 in_register_0000202d;
  
  while( true ) {
    if (head == (af_ep_desc_t *)0x0) {
      return true;
    }
    if ((uint)head->ep_id == CONCAT31(in_register_0000202d,ep_id)) break;
    head = head->next;
  }
  return false;
}

