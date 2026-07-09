/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> identify.o -> ezb_zcl_identify_cluster_server_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void ezb_zcl_identify_cluster_server_init(undefined4 param_1)

{
  int iVar1;
  undefined1 *puVar2;
  undefined1 auStack_24 [24];
  
  memcpy(auStack_24,&_LANCHOR0,0x14);
  iVar1 = identify_srv_get_attr_desc_part_0(param_1);
  if (iVar1 != 0) goto _L46;
  do {
    do {
      iVar1 = __assert_func(0,0,0,0);
_L46:
      puVar2 = (undefined1 *)calloc(1,0x14);
      *(undefined1 **)(iVar1 + 8) = puVar2;
    } while (puVar2 == (undefined1 *)0x0);
    *puVar2 = (char)param_1;
    milli_timer_init(puVar2 + 4,identify_timer_handler,puVar2);
    iVar1 = zcl_cluster_template_add(auStack_24);
  } while (iVar1 != 0);
  return;
}

