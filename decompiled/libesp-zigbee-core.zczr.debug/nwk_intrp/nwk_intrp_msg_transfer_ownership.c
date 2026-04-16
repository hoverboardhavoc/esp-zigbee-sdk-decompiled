/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_intrp.o -> nwk_intrp_msg_transfer_ownership
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

zmsg_t * nwk_intrp_msg_transfer_ownership(zmsg_t **msg)

{
  zmsg_t *pzVar1;
  
  pzVar1 = (zmsg_t *)msg;
  if ((msg != (zmsg_t **)0x0) && (pzVar1 = *msg, pzVar1 != (zmsg_t *)0x0)) {
    *msg = (zmsg_t *)0x0;
    return pzVar1;
  }
  return pzVar1;
}

