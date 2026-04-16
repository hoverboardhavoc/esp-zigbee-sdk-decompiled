/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> time.o -> ezb_zcl_time_cluster_server_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Variable defined which should be unmapped: template */
/* WARNING: Unknown calling convention */

void ezb_zcl_time_cluster_server_init(uint8_t ep_id)

{
  undefined3 in_register_00002029;
  int iVar1;
  void *pvVar2;
  undefined1 auStack_24 [4];
  zcl_cluster_template_t template;
  
  memcpy(auStack_24,&_LANCHOR0,0x14);
  iVar1 = ezb_zcl_get_attr_desc(CONCAT31(in_register_00002029,ep_id),10,1,0xeffe,0x131b);
  if ((iVar1 != 0) && (pvVar2 = calloc(1,0x28), pvVar2 != (void *)0x0)) {
    *(void **)(iVar1 + 8) = pvVar2;
    milli_timer_init((int)pvVar2 + 0xc,zcl_time_server_sync_finished,pvVar2);
    *(uint8_t *)((int)pvVar2 + 0x25) = ep_id;
    iVar1 = zcl_cluster_template_add(auStack_24);
    if (iVar1 == 0) {
      return;
    }
  }
  __assert_func(0,0,0,0);
  return;
}

