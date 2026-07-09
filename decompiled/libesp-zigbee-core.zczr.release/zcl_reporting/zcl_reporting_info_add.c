/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> zcl_reporting.o -> zcl_reporting_info_add
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 zcl_reporting_info_add(char *param_1)

{
  char cVar1;
  int iVar2;
  undefined4 *puVar3;
  char *pcVar4;
  undefined4 uVar5;
  undefined4 uStack_2c;
  undefined2 uStack_28;
  char cStack_26;
  undefined1 uStack_25;
  undefined1 uStack_24;
  undefined1 uStack_23;
  undefined1 uStack_22;
  undefined1 uStack_21;
  undefined1 uStack_20;
  undefined1 uStack_1f;
  undefined1 uStack_1e;
  undefined1 uStack_1d;
  undefined1 uStack_1c;
  undefined1 uStack_1b;
  undefined1 uStack_1a;
  undefined1 auStack_19 [9];
  
  if (param_1 == (char *)0x0) {
    return 2;
  }
  iVar2 = af_get_ep_desc(param_1[1]);
  if (iVar2 == 0) {
    uVar5 = 5;
  }
  else {
    puVar3 = (undefined4 *)calloc(1,8);
    if (puVar3 != (undefined4 *)0x0) {
      *(undefined4 *)(param_1 + 0x34) = *(undefined4 *)(iVar2 + 8);
      *(char **)(iVar2 + 8) = param_1;
      cVar1 = *param_1;
      *puVar3 = param_1;
      if (cVar1 == '\0') {
        param_1[9] = param_1[9] & 0xf0U | 0x11;
      }
      puVar3[1] = puVar3 + 1;
      iVar2 = core_globals_get();
      puVar3[1] = *(undefined4 *)(iVar2 + 0xd34);
      *(undefined4 **)(iVar2 + 0xd34) = puVar3 + 1;
      pcVar4 = (char *)*puVar3;
      memset(&uStack_2c,0,0x1b);
      zcl_reporting_remove_stored_reporting_info(pcVar4);
      uStack_28 = *(undefined2 *)(pcVar4 + 4);
      uStack_2c = *(undefined4 *)pcVar4;
      cStack_26 = pcVar4[8];
      uStack_25 = (undefined1)*(undefined2 *)(pcVar4 + 6);
      uStack_24 = (undefined1)((ushort)*(undefined2 *)(pcVar4 + 6) >> 8);
      uStack_23 = (undefined1)*(undefined4 *)(pcVar4 + 0x30);
      uStack_22 = (undefined1)((uint)*(undefined4 *)(pcVar4 + 0x30) >> 8);
      uStack_21 = (undefined1)*(undefined2 *)(pcVar4 + 0x10);
      uStack_20 = (undefined1)((ushort)*(undefined2 *)(pcVar4 + 0x10) >> 8);
      if (*pcVar4 == '\0') {
        uStack_1f = (undefined1)*(undefined2 *)(pcVar4 + 0x12);
        uStack_1e = (undefined1)((ushort)*(undefined2 *)(pcVar4 + 0x12) >> 8);
        uStack_1d = (undefined1)*(undefined4 *)(pcVar4 + 0x28);
        uStack_1c = (undefined1)((uint)*(undefined4 *)(pcVar4 + 0x28) >> 8);
        uStack_1b = (undefined1)*(undefined2 *)(pcVar4 + 0x2a);
        uStack_1a = (undefined1)((ushort)*(undefined2 *)(pcVar4 + 0x2a) >> 8);
        memcpy(auStack_19,pcVar4 + 0x18,8);
      }
      uVar5 = ds_internal_add_entry(10,&uStack_2c,0x1b);
      return uVar5;
    }
    uVar5 = 1;
  }
  return uVar5;
}

