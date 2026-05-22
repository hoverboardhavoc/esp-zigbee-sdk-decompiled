/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.release -> zdo_management.o -> nwk_leave_confirm
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Removing unreachable block (ram,0x00010054) */
/* WARNING: Unknown calling convention */

void nwk_leave_confirm(nwk_leave_cnf_t *cnf)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  ezb_shortaddr_t eVar3;
  undefined2 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  byte bVar7;
  byte *pbVar8;
  int *piVar9;
  ezb_shortaddr_t *peVar10;
  anon_union_12_2_2364703c_for_nwk_leave_cnf_s_1 *paVar11;
  undefined2 uStack_24;
  undefined1 auStack_22 [18];
  
  zdo_mgmt_leave_confirm(cnf);
  if (cnf->status != '\0') {
    return;
  }
  paVar11 = &cnf->field_1;
  bVar7 = *(byte *)((int)&cnf->field_1 + 10) & 1;
  if (*(int *)((int)&cnf->field_1 + 2) != 0 || *(int *)((int)&cnf->field_1 + 6) != 0) {
    piVar9 = (int *)nwk_get_extended_address();
    if ((*(int *)((int)&cnf->field_1 + 2) != *piVar9) ||
       (*(int *)((int)&cnf->field_1 + 6) != piVar9[1])) {
      aps_forget_device((paVar11->field_0).short_address,(undefined1 *)((int)&cnf->field_1 + 2));
      zdo_app_tc_handle_device_leaving(paVar11);
      memset(auStack_22,0,0x10);
      uStack_24 = 4;
      peVar10 = (ezb_shortaddr_t *)zdo_app_signal_get_params(&uStack_24);
      puVar1 = (undefined4 *)((int)&cnf->field_1 + 2);
      puVar2 = (undefined4 *)((int)&cnf->field_1 + 6);
      uVar4 = *(undefined2 *)puVar2;
      uVar5 = *puVar1;
      uVar6 = *puVar2;
      *(char *)(peVar10 + 1) = (char)*(undefined2 *)puVar1;
      *(char *)((int)peVar10 + 3) = (char)((uint)uVar5 >> 8);
      *(char *)((int)peVar10 + 5) = (char)((uint)uVar5 >> 0x18);
      *(char *)((int)peVar10 + 7) = (char)((uint)uVar6 >> 8);
      *(char *)((int)peVar10 + 9) = (char)((uint)uVar6 >> 0x18);
      eVar3 = (paVar11->field_0).short_address;
      *(char *)(peVar10 + 2) = (char)((uint)uVar5 >> 0x10);
      *(char *)(peVar10 + 3) = (char)uVar4;
      *(char *)(peVar10 + 4) = (char)((uint)uVar6 >> 0x10);
      *peVar10 = eVar3;
      *(byte *)(peVar10 + 5) = bVar7;
      goto _L0;
    }
  }
  aps_reset(*(ushort *)((int)&cnf->field_1 + 10) & 1);
  zdo_dev_set_joined(0);
  zdo_comm_handle_device_left(*(ushort *)((int)&cnf->field_1 + 10) & 1);
  memset(auStack_22,0,0x10);
  uStack_24 = 3;
  pbVar8 = (byte *)zdo_app_signal_get_params(&uStack_24);
  *pbVar8 = bVar7;
_L0:
  zdo_app_put_signal(&uStack_24);
  return;
}

