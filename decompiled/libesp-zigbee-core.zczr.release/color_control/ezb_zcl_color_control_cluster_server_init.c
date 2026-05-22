/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.release -> color_control.o -> ezb_zcl_color_control_cluster_server_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void ezb_zcl_color_control_cluster_server_init(uint8_t ep_id)

{
  zcl_attr_desc_t *pzVar1;
  void *__s;
  int iVar2;
  uint16_t attr_id;
  undefined1 auStack_24 [4];
  zcl_cluster_template_t template;
  
  memcpy(auStack_24,&_LANCHOR0,0x14);
  pzVar1 = color_control_srv_get_attr_desc(ep_id,attr_id);
  if (pzVar1 != (zcl_attr_desc_t *)0x0) goto _L927;
  do {
    do {
      pzVar1 = (zcl_attr_desc_t *)__assert_func(0,0,0,0);
_L927:
      __s = calloc(2,0x40);
      pzVar1->data_p = __s;
    } while (__s == (void *)0x0);
    memset(__s,0,0x80);
    iVar2 = zcl_cluster_template_add(auStack_24);
  } while (iVar2 != 0);
  return;
}

