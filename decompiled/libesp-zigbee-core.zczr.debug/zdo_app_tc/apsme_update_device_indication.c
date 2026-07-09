/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> zdo_app_tc.o -> apsme_update_device_indication
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void apsme_update_device_indication(undefined4 *param_1)

{
  char cVar1;
  undefined1 uVar2;
  int iVar3;
  void *__src;
  undefined4 uVar4;
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
  cVar1 = *(char *)((int)param_1 + 0x12);
  if (cVar1 == '\x02') {
    aps_forget_device(*(undefined2 *)(param_1 + 4),param_1 + 2);
    uVar4 = 0;
  }
  else {
    if (cVar1 == '\x03') {
      iVar3 = aps_secur_is_centralized();
      if (iVar3 == 0) {
        uVar4 = 2;
        goto _L0;
      }
    }
    else if (cVar1 != '\x01') {
      uVar4 = 0;
      goto _L0;
    }
    iVar3 = aps_secur_key_pair_find_or_create(param_1 + 2);
    if (iVar3 == 0) {
      uVar4 = 2;
    }
    else if ((*(ushort *)(iVar3 + 0x34) & 6) == 2) {
      uVar4 = 2;
    }
    else {
      iVar3 = aps_secur_tc_setup_key_pair();
      if (iVar3 == 0) {
        uStack_34 = CONCAT31(uStack_34._1_3_,1);
        uStack_1c = CONCAT22(*(undefined2 *)param_1,(undefined2)uStack_1c);
        uStack_18 = CONCAT22(*(undefined2 *)(param_1 + 1),(short)((uint)*param_1 >> 0x10));
        uStack_14 = (undefined2)((uint)param_1[1] >> 0x10);
        uStack_3c = param_1[2];
        uStack_38 = param_1[3];
        uVar2 = nwk_secur_get_current_key_seq();
        uStack_24._0_2_ = CONCAT11(uVar2,(undefined1)uStack_24);
        __src = (void *)nwk_secur_get_key_by_seq();
        memcpy((void *)((int)&uStack_34 + 1),__src,0x10);
        iVar3 = apsme_transport_key_request(&uStack_3c);
        if (iVar3 == 0) {
          uVar4 = 0;
        }
        else {
          log_write(2,"zdo_app_tc.c","TransportKey failed(0x%x)",iVar3);
          uVar4 = 2;
        }
      }
      else {
        uVar4 = 1;
      }
    }
  }
_L0:
  zdo_tc_put_device_update_signal(param_1,uVar4);
  return;
}

