/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> level.o -> ezb_zcl_level_cluster_server_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void ezb_zcl_level_cluster_server_init(uint8_t ep_id)

{
  zcl_attr_desc_t *pzVar1;
  void *__s;
  int iVar2;
  uint16_t attr_id;
  undefined1 auStack_24 [4];
  zcl_cluster_template_t template;
  
  memcpy(auStack_24,&_LANCHOR0,0x14);
  pzVar1 = level_srv_get_attr_desc(ep_id,attr_id);
  if (pzVar1 != (zcl_attr_desc_t *)0x0) goto _L249;
  do {
    do {
      pzVar1 = (zcl_attr_desc_t *)__assert_func(0,0,0,0);
_L249:
      __s = calloc(1,0x3c);
      pzVar1->data_p = __s;
    } while (__s == (void *)0x0);
    memset(__s,0,0x3c);
    iVar2 = zcl_cluster_template_add(auStack_24);
  } while (iVar2 != 0);
  return;
}

