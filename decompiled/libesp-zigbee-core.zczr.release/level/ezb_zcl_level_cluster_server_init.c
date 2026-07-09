/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> level.o -> ezb_zcl_level_cluster_server_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void ezb_zcl_level_cluster_server_init(undefined4 param_1)

{
  int iVar1;
  void *__s;
  undefined1 auStack_24 [28];
  
  memcpy(auStack_24,&_LANCHOR0,0x14);
  iVar1 = level_srv_get_attr_desc_part_0(param_1);
  if (iVar1 != 0) goto _L249;
  do {
    do {
      iVar1 = __assert_func(0,0,0,0);
_L249:
      __s = calloc(1,0x40);
      *(void **)(iVar1 + 8) = __s;
    } while (__s == (void *)0x0);
    memset(__s,0,0x40);
    iVar1 = zcl_cluster_template_add(auStack_24);
  } while (iVar1 != 0);
  return;
}

