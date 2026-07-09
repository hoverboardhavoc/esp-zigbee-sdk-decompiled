/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> on_off.o -> ezb_zcl_on_off_cluster_server_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void ezb_zcl_on_off_cluster_server_init(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  undefined1 *puVar3;
  undefined1 auStack_24 [24];
  
  memcpy(auStack_24,&_LANCHOR0,0x14);
  iVar1 = on_off_srv_get_attr_desc(param_1,0x4001);
  iVar2 = on_off_srv_get_attr_desc(param_1,0x4002);
  if (iVar1 == 0) goto _L0;
  if (iVar2 == 0) goto _L0;
  iVar1 = on_off_srv_get_attr_desc_part_0(param_1);
  if (iVar1 != 0) goto _L0;
  do {
    do {
      __assert_func(0,0,0,0);
_L0:
      puVar3 = (undefined1 *)calloc(1,0x14);
      *(undefined1 **)(iVar1 + 8) = puVar3;
    } while (puVar3 == (undefined1 *)0x0);
    *puVar3 = (char)param_1;
    milli_timer_init(puVar3 + 4,on_off_timer_handler,puVar3);
_L0:
    iVar2 = zcl_cluster_template_add(auStack_24);
  } while (iVar2 != 0);
  return;
}

