/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> on_off.o -> on_off_timer_start
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void on_off_timer_start(uint8_t ep_id,uint32_t delay)

{
  undefined3 in_register_00002029;
  zcl_attr_desc_t *pzVar1;
  
  pzVar1 = on_off_srv_get_attr_desc(ep_id,(uint16_t)delay);
  if (pzVar1 != (zcl_attr_desc_t *)0x0) {
                    /* WARNING: Load size is inaccurate */
    if ((uint)*pzVar1->data_p == CONCAT31(in_register_00002029,ep_id)) {
      milli_timer_start((byte *)((int)pzVar1->data_p + 4),100);
      return;
    }
  }
  return;
}

