/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> time.o -> time_server_ctx_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t time_server_ctx_init(uint8_t ep_id)

{
  zcl_attr_desc_t *pzVar1;
  void *pvVar2;
  ezb_err_t eVar3;
  
  pzVar1 = time_server_get_manufacturer_attr_desc(ep_id,0xeffe);
  if (pzVar1 == (zcl_attr_desc_t *)0x0) {
    eVar3 = 5;
  }
  else {
    pvVar2 = calloc(1,0x28);
    if (pvVar2 == (void *)0x0) {
      eVar3 = 1;
    }
    else {
      pzVar1->data_p = pvVar2;
      milli_timer_init((int)pvVar2 + 0xc,zcl_time_server_sync_finished,pvVar2);
      *(uint8_t *)((int)pvVar2 + 0x25) = ep_id;
      eVar3 = 0;
    }
  }
  return eVar3;
}

