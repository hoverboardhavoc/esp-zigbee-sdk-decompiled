/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> af_desc.o -> af_endpoint_is_gateway
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

_Bool af_endpoint_is_gateway(uint8_t ep_id)

{
  _Bool _Var1;
  af_ep_desc_t *paVar2;
  
  paVar2 = af_get_ep_desc(ep_id);
  if (paVar2 == (af_ep_desc_t *)0x0) {
    _Var1 = false;
  }
  else {
    _Var1 = (_Bool)(paVar2->ep_mask & 1);
  }
  return _Var1;
}

