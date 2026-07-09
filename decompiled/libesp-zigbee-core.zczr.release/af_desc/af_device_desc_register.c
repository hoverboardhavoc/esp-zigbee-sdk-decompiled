/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> af_desc.o -> af_device_desc_register
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int af_device_desc_register(int param_1)

{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  void *pvVar4;
  undefined2 *puVar5;
  uint uVar6;
  int iVar7;
  undefined2 *puVar8;
  byte bVar9;
  undefined4 uStack_28;
  undefined4 uStack_24;
  
  if (param_1 == 0) {
    return 3;
  }
  iVar3 = core_globals_get();
  *(int *)(iVar3 + 0xca0) = param_1;
  iVar3 = core_globals_get();
  uStack_28 = 0xa1e000f2;
  iVar7 = *(int *)(iVar3 + 0xca0);
  uStack_24 = 0x60;
  iVar3 = nwk_is_device_zczr();
  if ((iVar3 != 0) && (iVar7 != 0)) {
    uVar1 = af_create_endpoint_desc(&uStack_28);
    uVar2 = zcl_create_cluster_desc(0x21,2,0);
    iVar3 = af_endpoint_add_cluster_desc(uVar1,uVar2);
    if (iVar3 != 0) goto _L0;
    iVar3 = af_device_add_endpoint_desc(iVar7,uVar1);
    if (iVar3 != 0) {
      uVar2 = 0;
      goto _L0;
    }
  }
  uVar2 = 0;
  uVar1 = 0;
_L0:
  zcl_free_cluster_desc(uVar2);
  af_free_endpoint_desc(uVar1);
  iVar3 = core_globals_get();
  if (*(int **)(iVar3 + 0xca0) == (int *)0x0) {
_L0:
    iVar7 = 2;
_L0:
    iVar3 = core_globals_get();
    *(undefined4 *)(iVar3 + 0xca0) = 0;
  }
  else {
    bVar9 = 0;
    for (iVar3 = **(int **)(iVar3 + 0xca0); iVar3 != 0; iVar3 = *(int *)(iVar3 + 0x1c)) {
      af_ep_desc_init(iVar3);
      puVar8 = *(undefined2 **)(iVar3 + 4);
      for (puVar5 = puVar8; puVar5 != (undefined2 *)0x0; puVar5 = *(undefined2 **)(puVar5 + 8)) {
        if (*(char *)(puVar5 + 1) == '\x01') {
          *(char *)(iVar3 + 0x13) = *(char *)(iVar3 + 0x13) + '\x01';
        }
        else {
          if (*(char *)(puVar5 + 1) != '\x02') goto _L0;
          *(char *)(iVar3 + 0x14) = *(char *)(iVar3 + 0x14) + '\x01';
        }
      }
      uVar2 = (uint)*(byte *)(iVar3 + 0x13);
      iVar7 = *(byte *)(iVar3 + 0x14) + uVar2;
      if (iVar7 != 0) {
_L0:
        pvVar4 = calloc(1,iVar7 << 1);
        *(void **)(iVar3 + 0x18) = pvVar4;
        if (pvVar4 != (void *)0x0) {
          uVar6 = 0;
          do {
            if (puVar8 == (undefined2 *)0x0) goto _L0;
            if (*(char *)(puVar8 + 1) == '\x01') {
              *(undefined2 *)(uVar6 * 2 + (int)pvVar4) = *puVar8;
              uVar6 = uVar6 + 1 & 0xffff;
            }
            else {
              if (*(char *)(puVar8 + 1) != '\x02') goto _L0;
              *(undefined2 *)(uVar2 * 2 + (int)pvVar4) = *puVar8;
              uVar2 = uVar2 + 1 & 0xffff;
            }
            puVar8 = *(undefined2 **)(puVar8 + 8);
          } while( true );
        }
        iVar7 = 1;
        goto _L0;
      }
_L0:
      af_add_simple_desc(iVar3 + 0xc);
      iVar7 = af_ep_reporting_info_init(iVar3);
      if (iVar7 != 0) goto _L0;
      if (s_ep_num_on_dev <= bVar9) goto _L0;
      bVar9 = bVar9 + 1;
      uVar2 = 0;
    }
    zcl_reporting_start();
    iVar7 = 0;
  }
  return iVar7;
_L0:
  iVar7 = __assert_func(0,0,0,0);
  goto _L0;
}

