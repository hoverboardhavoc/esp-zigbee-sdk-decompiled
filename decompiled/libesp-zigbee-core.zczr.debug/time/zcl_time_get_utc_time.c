/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> time.o -> zcl_time_get_utc_time
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

uint32_t zcl_time_get_utc_time(uint8_t ep_id)

{
  zcl_time_server_time_ctx_t *pzVar1;
  uint32_t uVar2;
  _func_uint32_t *p_Var3;
  
  pzVar1 = time_server_get_time_ctx(ep_id);
  if (pzVar1 == (zcl_time_server_time_ctx_t *)0x0) {
    uVar2 = 0xffffffff;
  }
  else {
    p_Var3 = (pzVar1->interface).get_utc_time;
    if (p_Var3 == (_func_uint32_t *)0x0) {
      uVar2 = 0xffffffff;
    }
    else {
      uVar2 = (*p_Var3)();
    }
  }
  return uVar2;
}

