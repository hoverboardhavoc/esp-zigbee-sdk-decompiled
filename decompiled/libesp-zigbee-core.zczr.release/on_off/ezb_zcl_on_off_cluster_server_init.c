/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> on_off.o -> ezb_zcl_on_off_cluster_server_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void ezb_zcl_on_off_cluster_server_init(uint8_t ep_id)

{
  zcl_attr_desc_t *pzVar1;
  zcl_attr_desc_t *pzVar2;
  uint8_t *puVar3;
  int iVar4;
  uint16_t attr_id;
  undefined1 auStack_24 [4];
  zcl_cluster_template_t template;
  
  memcpy(auStack_24,&_LANCHOR0,0x14);
  pzVar1 = on_off_srv_get_attr_desc(ep_id,0x4001);
  pzVar2 = on_off_srv_get_attr_desc(ep_id,0x4002);
  if (pzVar1 == (zcl_attr_desc_t *)0x0) goto _L0;
  if (pzVar2 == (zcl_attr_desc_t *)0x0) goto _L0;
  pzVar1 = on_off_srv_get_attr_desc(ep_id,attr_id);
  if (pzVar1 != (zcl_attr_desc_t *)0x0) goto _L0;
  do {
    do {
      __assert_func(0,0,0,0);
_L0:
      puVar3 = (uint8_t *)calloc(1,0x14);
      pzVar1->data_p = puVar3;
    } while (puVar3 == (uint8_t *)0x0);
    *puVar3 = ep_id;
    milli_timer_init(puVar3 + 4,on_off_timer_handler,puVar3);
_L0:
    iVar4 = zcl_cluster_template_add(auStack_24);
  } while (iVar4 != 0);
  return;
}

