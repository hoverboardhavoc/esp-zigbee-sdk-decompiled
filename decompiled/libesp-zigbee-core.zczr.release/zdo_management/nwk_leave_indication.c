/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> zdo_management.o -> nwk_leave_indication
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void nwk_leave_indication(nwk_leave_ind_t *ind)

{
  undefined4 *puVar1;
  ezb_shortaddr_t eVar2;
  undefined2 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  byte bVar6;
  byte *pbVar7;
  int *piVar8;
  ezb_shortaddr_t *peVar9;
  undefined2 uStack_24;
  undefined1 auStack_22 [18];
  
  bVar6 = ind->field_0xa & 1;
  if (*(int *)&(ind->device_address).field_0 != 0 ||
      *(int *)((int)&(ind->device_address).field_0 + 4) != 0) {
    piVar8 = (int *)nwk_get_extended_address();
    if ((*(int *)&(ind->device_address).field_0 != *piVar8) ||
       (*(int *)((int)&(ind->device_address).field_0 + 4) != piVar8[1])) {
      aps_forget_device(ind->short_address,&ind->device_address);
      zdo_app_tc_handle_device_leaving(ind);
      memset(auStack_22,0,0x10);
      uStack_24 = 4;
      peVar9 = (ezb_shortaddr_t *)zdo_app_signal_get_params(&uStack_24);
      puVar1 = (undefined4 *)((int)&(ind->device_address).field_0 + 4);
      uVar3 = *(undefined2 *)puVar1;
      uVar4 = *(undefined4 *)&(ind->device_address).field_0;
      uVar5 = *puVar1;
      *(char *)(peVar9 + 1) = (char)*(undefined2 *)&(ind->device_address).field_0;
      *(char *)((int)peVar9 + 3) = (char)((uint)uVar4 >> 8);
      *(char *)((int)peVar9 + 5) = (char)((uint)uVar4 >> 0x18);
      *(char *)((int)peVar9 + 7) = (char)((uint)uVar5 >> 8);
      *(char *)((int)peVar9 + 9) = (char)((uint)uVar5 >> 0x18);
      eVar2 = ind->short_address;
      *(char *)(peVar9 + 2) = (char)((uint)uVar4 >> 0x10);
      *(char *)(peVar9 + 3) = (char)uVar3;
      *(char *)(peVar9 + 4) = (char)((uint)uVar5 >> 0x10);
      *peVar9 = eVar2;
      *(byte *)(peVar9 + 5) = bVar6;
      goto _L0;
    }
  }
  zdo_secur_handle_device_left();
  aps_reset();
  zdo_dev_set_joined(0);
  zdo_comm_handle_device_left(*(ushort *)&ind->field_0xa & 1);
  memset(auStack_22,0,0x10);
  uStack_24 = 3;
  pbVar7 = (byte *)zdo_app_signal_get_params(&uStack_24);
  *pbVar7 = bVar6;
_L0:
  zdo_app_put_signal(&uStack_24);
  return;
}

