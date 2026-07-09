/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> ias_zone.o -> ias_zone_ctx_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int ias_zone_ctx_init(undefined4 param_1)

{
  void *pvVar1;
  int iVar2;
  int extraout_a1;
  char *pcVar3;
  
  pvVar1 = calloc(1,0x14);
  if (pvVar1 != (void *)0x0) {
    iVar2 = ias_zone_srv_get_attr_desc(param_1,0xeff0);
    *(void **)(iVar2 + 8) = pvVar1;
    return 0;
  }
  pcVar3 = "ias_zone_ctx_init";
  iVar2 = __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/ias_zone.c",
                        0x217,"ias_zone_ctx_init","ctx != ((void *)0)");
  if (extraout_a1 == 0x10) {
    iVar2 = ias_zone_cie_address_attr_write_handler
                      (*(undefined1 *)(iVar2 + 0x15),*(undefined1 *)(iVar2 + 0x14),
                       *(undefined2 *)(iVar2 + 2),pcVar3);
  }
  return iVar2;
}

