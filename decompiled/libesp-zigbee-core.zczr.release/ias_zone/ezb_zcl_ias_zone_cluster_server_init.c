/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> ias_zone.o -> ezb_zcl_ias_zone_cluster_server_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void ezb_zcl_ias_zone_cluster_server_init(undefined4 param_1)

{
  void *pvVar1;
  int iVar2;
  int iVar3;
  undefined1 auStack_24 [24];
  
  memcpy(auStack_24,&_LANCHOR0,0x14);
  pvVar1 = calloc(1,0x14);
  if (pvVar1 != (void *)0x0) goto _L0;
  do {
    pvVar1 = (void *)__assert_func(0,0,0,0);
_L0:
    iVar2 = ezb_zcl_get_attr_desc(param_1,0x500,1,0xeff0,0x131b);
    *(void **)(iVar2 + 8) = pvVar1;
    iVar2 = zcl_cluster_template_add(auStack_24);
  } while (iVar2 != 0);
  iVar2 = ias_zone_srv_get_attr_desc(param_1,0x10);
  iVar3 = **(int **)(iVar2 + 8);
  if (((*(int **)(iVar2 + 8))[1] + 1U != (uint)(iVar3 == 0)) || (iVar3 - 1U < 0xfffffffe)) {
    iVar2 = ias_zone_srv_get_attr_desc(param_1,0);
    if (**(char **)(iVar2 + 8) == '\x01') {
      iVar2 = ias_zone_srv_get_zone_ctx(param_1);
      *(undefined1 *)(iVar2 + 2) = 1;
    }
    else {
      log_write("ZCL_IAS_ZONE","CIE address restored, but zone state is not enrolled");
    }
  }
  return;
}

