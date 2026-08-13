/*
 * Last changed at upstream commit ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * https://github.com/espressif/esp-zigbee-sdk/commit/ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * Upstream date: 2026-08-13 06:13:24 +0000
 * Upstream subject: change: update esp-zigbee-lib (e4bad48f)
 * Source: libesp-zigbee-core.zczr.debug -> datasets.o -> ds_save_common_data
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Control flow encountered bad instruction data */

void ds_save_common_data(void)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  void *__src;
  undefined1 auStack_54 [2];
  undefined2 uStack_52;
  undefined2 uStack_50;
  undefined2 uStack_4e;
  undefined2 uStack_4c;
  undefined2 uStack_4a;
  undefined2 uStack_48;
  byte bStack_46;
  undefined1 uStack_45;
  undefined1 uStack_44;
  undefined1 uStack_43;
  undefined1 uStack_42;
  undefined1 uStack_41;
  undefined1 uStack_40;
  undefined1 uStack_3f;
  undefined1 uStack_3e;
  undefined1 uStack_3d;
  undefined1 uStack_3c;
  undefined1 uStack_3b;
  undefined1 uStack_3a;
  undefined1 uStack_39;
  undefined1 uStack_38;
  undefined1 uStack_37;
  undefined1 uStack_36;
  undefined1 uStack_35;
  undefined1 uStack_34;
  undefined1 uStack_33;
  undefined1 uStack_32;
  undefined1 uStack_31;
  undefined1 uStack_30;
  undefined1 uStack_2f;
  undefined1 uStack_2e;
  undefined1 uStack_2d;
  undefined1 uStack_2c;
  undefined1 uStack_2b;
  undefined1 uStack_2a;
  undefined1 uStack_29;
  undefined1 uStack_28;
  undefined1 uStack_27;
  byte bStack_26;
  undefined1 uStack_25;
  undefined1 uStack_24;
  undefined1 uStack_23;
  undefined1 uStack_22;
  undefined1 auStack_21 [16];
  undefined1 uStack_11;
  
  memset(auStack_54,0,0x44);
  iVar2 = core_globals_get();
  uStack_52 = (undefined2)*(undefined3 *)(iVar2 + 0xc);
  uStack_50 = (undefined2)((uint)*(undefined4 *)(iVar2 + 0xc) >> 0x10);
  uStack_4e = (undefined2)*(undefined3 *)(iVar2 + 0x10);
  uStack_4c = (undefined2)((uint)*(undefined4 *)(iVar2 + 0x10) >> 0x10);
  iVar2 = core_globals_get();
  uStack_4a = (undefined2)*(undefined4 *)(iVar2 + 8);
  uStack_48 = (undefined2)((uint)*(undefined4 *)(iVar2 + 8) >> 0x10);
  iVar2 = core_globals_get();
  bStack_46 = bStack_46 & 0xfe | (byte)(*(uint *)(iVar2 + 0x18) >> 4) & 1;
  iVar2 = core_globals_get();
  bStack_46 = (byte)((*(uint *)(iVar2 + 0x18) >> 5 & 1) << 1) | bStack_46 & 0xfd;
  iVar2 = core_globals_get();
  uStack_3d = (undefined1)*(undefined2 *)(iVar2 + 0x9e4);
  uStack_3c = (undefined1)((ushort)*(undefined2 *)(iVar2 + 0x9e4) >> 8);
  iVar2 = core_globals_get();
  uVar3 = *(undefined4 *)(iVar2 + 0x9ef);
  uVar1 = *(undefined4 *)(iVar2 + 0x9f3);
  uStack_3b = (undefined1)*(undefined3 *)(iVar2 + 0x9ef);
  uStack_3a = (undefined1)((uint)uVar3 >> 8);
  uStack_39 = (undefined1)((uint)uVar3 >> 0x10);
  uStack_38 = (undefined1)((uint)uVar3 >> 0x18);
  uStack_37 = (undefined1)*(undefined3 *)(iVar2 + 0x9f3);
  uStack_36 = (undefined1)((uint)uVar1 >> 8);
  uStack_35 = (undefined1)((uint)uVar1 >> 0x10);
  uStack_34 = (undefined1)((uint)uVar1 >> 0x18);
  iVar2 = core_globals_get();
  uStack_33 = (undefined1)*(undefined2 *)(iVar2 + 0x9e2);
  uStack_32 = (undefined1)((ushort)*(undefined2 *)(iVar2 + 0x9e2) >> 8);
  iVar2 = core_globals_get();
  uVar3 = *(undefined4 *)(iVar2 + 0x9e6);
  uVar1 = *(undefined4 *)(iVar2 + 0x9ea);
  uStack_31 = (undefined1)*(undefined3 *)(iVar2 + 0x9e6);
  uStack_30 = (undefined1)((uint)uVar3 >> 8);
  uStack_2f = (undefined1)((uint)uVar3 >> 0x10);
  uStack_2e = (undefined1)((uint)uVar3 >> 0x18);
  uStack_2d = (undefined1)*(undefined3 *)(iVar2 + 0x9ea);
  uStack_2c = (undefined1)((uint)uVar1 >> 8);
  uStack_2b = (undefined1)((uint)uVar1 >> 0x10);
  uStack_2a = (undefined1)((uint)uVar1 >> 0x18);
  iVar2 = core_globals_get();
  uStack_29 = (undefined1)*(undefined2 *)(iVar2 + 0x9dc);
  uStack_28 = (undefined1)((ushort)*(undefined2 *)(iVar2 + 0x9dc) >> 8);
  uStack_27 = nwk_get_update_id();
  bStack_26 = bStack_26 & 0xf0 | 2;
  iVar2 = core_globals_get();
  bStack_26 = bStack_26 & 0xcf | (byte)((*(uint *)(iVar2 + 0xa2c) & 3) << 4);
  iVar2 = core_globals_get();
  bStack_26 = bStack_26 & 0xbf | (byte)((*(byte *)(iVar2 + 0x9ee) & 1) << 6);
  uVar3 = nwk_get_pan_channel();
  uStack_25 = (undefined1)uVar3;
  uStack_24 = (undefined1)((uint)uVar3 >> 8);
  uStack_23 = (undefined1)((uint)uVar3 >> 0x10);
  uStack_22 = (undefined1)((uint)uVar3 >> 0x18);
  puVar4 = (undefined4 *)aps_secur_get_tc_address();
  uVar3 = *puVar4;
  uVar1 = puVar4[1];
  uStack_45 = (undefined1)*(undefined3 *)puVar4;
  uStack_44 = (undefined1)((uint)uVar3 >> 8);
  uStack_43 = (undefined1)((uint)uVar3 >> 0x10);
  uStack_42 = (undefined1)((uint)uVar3 >> 0x18);
  uStack_41 = (undefined1)*(undefined3 *)(puVar4 + 1);
  uStack_40 = (undefined1)((uint)uVar1 >> 8);
  uStack_3f = (undefined1)((uint)uVar1 >> 0x10);
  uStack_3e = (undefined1)((uint)uVar1 >> 0x18);
  uStack_11 = nwk_secur_get_current_key_seq();
  __src = (void *)nwk_secur_get_key_by_seq();
  memcpy(auStack_21,__src,0x10);
  iVar2 = ezb_plat_datasets_set(1,auStack_54,0x44);
  ds_log(1,iVar2,0);
  if (iVar2 == 0) {
    return;
  }
  __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/common/datasets.c",0xee,
                "ds_save_common_data","(error) == 0");
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

