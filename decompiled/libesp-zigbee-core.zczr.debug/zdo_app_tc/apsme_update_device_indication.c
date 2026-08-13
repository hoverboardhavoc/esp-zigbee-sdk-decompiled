/*
 * Last changed at upstream commit ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * https://github.com/espressif/esp-zigbee-sdk/commit/ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * Upstream date: 2026-08-13 06:13:24 +0000
 * Upstream subject: change: update esp-zigbee-lib (e4bad48f)
 * Source: libesp-zigbee-core.zczr.debug -> zdo_app_tc.o -> apsme_update_device_indication
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void apsme_update_device_indication(undefined4 *param_1)

{
  byte bVar1;
  undefined4 uVar2;
  undefined1 uVar3;
  int iVar4;
  int iVar5;
  void *__src;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined2 uStack_14;
  undefined2 uStack_12;
  
  uStack_3c = 0;
  uStack_38 = 0;
  uStack_34 = 0;
  uStack_30 = 0;
  uStack_2c = 0;
  uStack_28 = 0;
  uStack_24 = 0;
  uStack_20 = 0;
  uStack_1c = 0;
  uStack_18 = 0;
  uStack_14 = 0;
  bVar1 = *(byte *)((int)param_1 + 0x12);
  if (bVar1 == 2) {
    aps_forget_device(*(undefined2 *)(param_1 + 4),param_1 + 2);
    uVar2 = 0;
    goto _L0;
  }
  if (bVar1 < 3) {
    if (bVar1 == 0) {
      uStack_12 = 0;
      iVar4 = nwk_address_update(param_1 + 2,*(undefined2 *)(param_1 + 4),&uStack_12);
      uVar2 = 0;
      if (iVar4 == 0xd) {
        nwk_raise_address_conflict(*(undefined2 *)(param_1 + 4));
      }
      goto _L0;
    }
    if (bVar1 != 1) {
      uVar2 = 0;
      goto _L0;
    }
  }
  else {
    if (bVar1 != 3) {
      uVar2 = 0;
      goto _L0;
    }
    iVar4 = aps_secur_is_centralized();
    if (iVar4 == 0) {
      uVar2 = 2;
      goto _L0;
    }
  }
  iVar4 = aps_secur_key_pair_find_or_create(param_1 + 2);
  if (iVar4 == 0) {
    uVar2 = 2;
  }
  else if ((*(ushort *)(iVar4 + 0x34) & 6) == 2) {
    uVar2 = 2;
  }
  else {
    if (*(char *)((int)param_1 + 0x12) == '\x01') {
      iVar4 = aps_secur_tc_setup_key_pair();
      uVar2 = 1;
      if (iVar4 != 0) goto _L0;
    }
    else {
      iVar5 = aps_secur_tcpol_get_allow_rejoins_with_well_known_key();
      if (iVar5 == 0) {
        if ((*(ushort *)(iVar4 + 0x34) & 6) != 4) {
          uVar2 = 1;
          goto _L0;
        }
      }
      else if (((*(ushort *)(iVar4 + 0x34) & 6) != 4) &&
              (iVar4 = aps_secur_tc_setup_key_pair(iVar4), iVar4 != 0)) {
        uVar2 = 1;
        goto _L0;
      }
    }
    uStack_34 = CONCAT31(uStack_34._1_3_,1);
    uStack_1c = CONCAT22(*(undefined2 *)param_1,(undefined2)uStack_1c);
    uStack_18 = CONCAT22(*(undefined2 *)(param_1 + 1),(short)((uint)*param_1 >> 0x10));
    uStack_14 = (undefined2)((uint)param_1[1] >> 0x10);
    uStack_3c = param_1[2];
    uStack_38 = param_1[3];
    uVar3 = nwk_secur_get_current_key_seq();
    uStack_24._0_2_ = CONCAT11(uVar3,(undefined1)uStack_24);
    __src = (void *)nwk_secur_get_key_by_seq();
    memcpy((void *)((int)&uStack_34 + 1),__src,0x10);
    iVar4 = apsme_transport_key_request(&uStack_3c);
    if (iVar4 == 0) {
      uVar2 = 0;
    }
    else {
      log_write(2,"zdo_app_tc.c","TransportKey failed(0x%x)",iVar4);
      uVar2 = 2;
    }
  }
_L0:
  zdo_tc_put_device_update_signal(param_1,uVar2);
  return;
}

