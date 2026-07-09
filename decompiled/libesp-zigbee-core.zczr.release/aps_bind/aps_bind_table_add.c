/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> aps_bind.o -> aps_bind_table_add
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int aps_bind_table_add(uint param_1,undefined2 *param_2,undefined4 param_3,byte *param_4,int param_5
                      )

{
  undefined2 uVar1;
  undefined2 *__s;
  int iVar2;
  size_t __n;
  undefined4 uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  undefined4 uVar7;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  
  if (((int)param_2 - 1U & 0xff) < 0xfe) {
    uVar4 = (uint)*param_4;
    if (uVar4 != 3) goto _L0;
    if (param_5 != 0) {
      do {
        __s = (undefined2 *)bind_table_find_src(param_1,param_2,param_3);
        if (__s == (undefined2 *)0x0) {
          iVar2 = core_globals_get();
          uVar7 = *(undefined4 *)(iVar2 + 0x968);
          iVar2 = core_globals_get();
          uVar3 = *(undefined4 *)(iVar2 + 0x96c);
          uVar1 = bind_src_size();
          iVar2 = core_globals_get();
          __s = (undefined2 *)mempool_alloc_ent(uVar7,uVar3,uVar1,*(undefined2 *)(iVar2 + 0x970));
          if (__s == (undefined2 *)0x0) {
            return 1;
          }
          __n = bind_src_size();
          memset(__s,0,__n);
          *__s = 0xffff;
          iVar2 = nwk_address_by_extended(param_1,1,__s);
          if (iVar2 != 0) goto _L0;
          *(char *)(__s + 1) = (char)param_2;
          __s[2] = (short)param_3;
        }
        param_2 = (undefined2 *)bind_table_find_dst(param_4,param_5);
        if (param_2 == (undefined2 *)0x0) {
          iVar2 = core_globals_get();
          uVar7 = *(undefined4 *)(iVar2 + 0x974);
          iVar2 = core_globals_get();
          uVar3 = *(undefined4 *)(iVar2 + 0x978);
          iVar2 = core_globals_get();
          param_2 = (undefined2 *)mempool_alloc_ent(uVar7,uVar3,6,*(undefined2 *)(iVar2 + 0x97c));
          if (param_2 == (undefined2 *)0x0) {
            iVar2 = 1;
_L0:
            iVar5 = bind_src_is_empty(__s);
            if (iVar5 != 0) {
              bind_src_table_free(__s);
              return iVar2;
            }
            return iVar2;
          }
          memset(param_2,0,6);
          if (*param_4 == 1) {
            *param_2 = *(undefined2 *)(param_4 + 2);
            *(byte *)((int)param_2 + 5) = *(byte *)((int)param_2 + 5) | 1;
          }
          else {
            iVar2 = nwk_address_by_extended(param_4 + 2,1,param_2);
            if (iVar2 != 0) {
              bind_dst_table_free(param_2);
              goto _L0;
            }
            *(char *)(param_2 + 1) = (char)param_5;
          }
        }
        iVar2 = core_globals_get();
        param_5 = 0x1000;
        iVar5 = (int)param_2 - *(int *)(iVar2 + 0x974) >> 1;
        param_1 = iVar5 * -0x55555555;
        iVar2 = core_globals_get();
        uVar4 = param_1 & 0xffff;
        if (uVar4 < *(ushort *)(iVar2 + 0x97c)) {
          uVar6 = 1 << (param_1 & 7) & 0xff;
          uVar4 = __atomic_fetch_or_1(((uint)(iVar5 * -0x55550000) >> 0x13) + 6 + (int)__s,uVar6,5);
          if ((uVar6 & uVar4) != 0) {
            return 0;
          }
          *(char *)(param_2 + 2) = *(char *)(param_2 + 2) + '\x01';
          iVar2 = core_globals_get();
          if ((*(uint *)(iVar2 + 0x980) & 1) != 0) {
            return 0;
          }
          uStack_3c = 0;
          uStack_38 = 0;
          uStack_34 = 0;
          aps_bind_table_remove_stored_bind(__s,param_2);
          uStack_3c._0_3_ = CONCAT12(*(undefined1 *)(__s + 1),__s[2]);
          uVar4 = *(byte *)((int)param_2 + 5) & 1;
          if ((*(byte *)((int)param_2 + 5) & 1) != 0) {
            uStack_3c = (uint)(uint3)uStack_3c;
            uStack_38 = CONCAT22(uStack_38._2_2_,*param_2);
_L0:
            ds_internal_add_entry(6,&uStack_3c,0xc);
            return 0;
          }
          iVar2 = nwk_address_extended_by_ref(&uStack_44);
          param_4 = (byte *)0x0;
          if (iVar2 == 0) {
            uStack_38 = uStack_44;
            uStack_34 = uStack_40;
            uStack_3c = CONCAT13(*(undefined1 *)(param_2 + 1),(uint3)uStack_3c);
            goto _L0;
          }
        }
        __assert_func(0,0,0,0);
_L0:
      } while (uVar4 == 1);
    }
  }
  return 2;
}

