/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> identify.o -> ezb_zcl_is_identifying
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

_Bool ezb_zcl_is_identifying(uint8_t ep_id)

{
  zcl_attr_desc_t *pzVar1;
  uint16_t in_a1;
  
  pzVar1 = identify_srv_get_attr_desc(ep_id,in_a1);
                    /* WARNING: Load size is inaccurate */
  return *pzVar1->data_p != 0;
}

