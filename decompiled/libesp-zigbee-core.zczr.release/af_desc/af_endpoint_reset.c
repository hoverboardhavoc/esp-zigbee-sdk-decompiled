/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> af_desc.o -> af_endpoint_reset
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 af_endpoint_reset(code *param_1)

{
  short *psVar1;
  undefined2 *puVar2;
  undefined1 *puVar3;
  undefined4 uVar4;
  
  puVar3 = (undefined1 *)af_get_ep_desc();
  if (puVar3 == (undefined1 *)0x0) {
    uVar4 = 5;
  }
  else {
    puVar2 = (undefined2 *)0x0;
    while ((puVar2 = (undefined2 *)af_endpoint_get_next_cluster_desc(puVar3,puVar2),
           puVar2 != (undefined2 *)0x0 && (param_1 != (code *)0x0))) {
      psVar1 = (short *)0x0;
      while (psVar1 = (short *)zcl_cluster_get_next_attr_desc(puVar2,psVar1), psVar1 != (short *)0x0
            ) {
        if ((*(char *)((int)psVar1 + 3) != '@') && (*psVar1 != -3)) {
          (*param_1)(*puVar3,*puVar2,*(undefined1 *)(puVar2 + 1),*(undefined4 *)(psVar1 + 4));
          zcl_write_attr_value(*(undefined4 *)(psVar1 + 4),(char)psVar1[1]);
        }
      }
    }
    uVar4 = 0;
  }
  return uVar4;
}

