/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> poll_control.o -> ezb_zcl_poll_control_cluster_server_deinit
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void ezb_zcl_poll_control_cluster_server_deinit(uint8_t ep_id)

{
  void *pvVar1;
  zcl_attr_desc_t *pzVar2;
  uint16_t in_a1;
  
  pzVar2 = poll_control_srv_get_attr_desc(ep_id,in_a1);
  if ((pzVar2 != (zcl_attr_desc_t *)0x0) && (pvVar1 = pzVar2->data_p, pvVar1 != (void *)0x0)) {
    milli_timer_stop((int)pvVar1 + 4);
    mm_free(pvVar1);
    return;
  }
  return;
}

