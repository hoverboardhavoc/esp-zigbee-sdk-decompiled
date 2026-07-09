/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> mac.o -> mac_pal_callback_rx_done
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void mac_pal_callback_rx_done(int *param_1,int param_2)

{
  char cVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  uint uVar5;
  undefined4 uVar6;
  uint uVar7;
  int *piVar8;
  code *pcVar9;
  undefined1 auStack_70 [12];
  undefined4 uStack_64;
  uint uStack_60;
  ushort uStack_5c;
  short sStack_56;
  undefined1 uStack_53;
  ushort uStack_52;
  undefined1 uStack_50;
  undefined1 uStack_4f;
  char cStack_4e;
  ushort *puStack_4c;
  int iStack_48;
  char cStack_44;
  byte abStack_3a [2];
  uint uStack_38;
  uint uStack_34;
  short sStack_30;
  short sStack_2e;
  ushort uStack_2c;
  undefined1 uStack_2a;
  byte bStack_28;
  ushort *puStack_24;
  
  iVar2 = s_devices;
  if (param_2 != 0) {
    return;
  }
  if ((*(uint *)(s_devices + 0x9c) & 1) == 0) {
    return;
  }
  if (param_1 == (int *)0x0) {
    return;
  }
  if (*param_1 == 0) {
    return;
  }
  iVar4 = mac_frame_parse(&iStack_48);
  if (iVar4 != 0) {
    return;
  }
  iVar4 = mac_filter_apply_to_rxframe(&iStack_48);
  if (iVar4 != 0) {
    return;
  }
  if ((uStack_2c & 8) != 0) {
    return;
  }
  cVar1 = *(char *)(iVar2 + 0x2e);
  if (cVar1 == '\x01') {
    if ((uStack_2c & 7) == 0) {
      pcVar9 = *(code **)(iVar2 + 0x38);
      if (pcVar9 == (code *)0x0) {
        return;
      }
      memset(&uStack_64,0,0x1c);
      if (bStack_28 < 4) {
        return;
      }
      if ((byte)puStack_24[1] != 0) {
        return;
      }
      if (*(byte *)((int)puStack_24 + 3) != 0) {
        return;
      }
      if ((~*puStack_24 & 0xfff) != 0) {
        return;
      }
      uStack_64._0_3_ = CONCAT12((uStack_2c & 0x3000) == 0x2000,(undefined2)uStack_64);
      if (abStack_3a[0] == 0) {
        return;
      }
      memcpy(&uStack_60,abStack_3a,10);
      sStack_56 = sStack_2e;
      if (sStack_2e == -1) {
        sStack_56 = sStack_30;
      }
      cStack_4e = bStack_28 - 4;
      puStack_4c = puStack_24 + 2;
      uStack_53 = *(undefined1 *)(iStack_48 + 5);
      uStack_50 = *(undefined1 *)(iStack_48 + 0x11);
      uStack_4f = *(undefined1 *)(iStack_48 + 0x10);
      uStack_52 = *puStack_24;
      uStack_64._0_2_ = CONCAT11(uStack_2a,(undefined1)uStack_64);
      (*pcVar9)(&uStack_64,*(undefined4 *)(iVar2 + 0x3c));
      return;
    }
_L0:
    if (*(char *)(iVar2 + 0x43) != *(char *)(iVar2 + 0x32)) {
      return;
    }
  }
  else if (cVar1 == '\x02') goto _L0;
  if ((uStack_2c & 7) != 1) {
    if ((uStack_2c & 7) != 3) {
      if ((uStack_2c & 7) != 0) {
        return;
      }
      memset(&uStack_64,0,0x1c);
      if (bStack_28 < 4) {
        return;
      }
      if ((byte)puStack_24[1] != 0) {
        return;
      }
      if (*(byte *)((int)puStack_24 + 3) != 0) {
        return;
      }
      if ((~*puStack_24 & 0xfff) != 0) {
        return;
      }
      uStack_64._0_3_ = CONCAT12((uStack_2c & 0x3000) == 0x2000,(undefined2)uStack_64);
      if (abStack_3a[0] == 0) {
        return;
      }
      memcpy(&uStack_60,abStack_3a,10);
      sStack_56 = sStack_2e;
      if (sStack_2e == -1) {
        sStack_56 = sStack_30;
      }
      puStack_4c = puStack_24 + 2;
      cStack_4e = bStack_28 - 4;
      uStack_53 = *(undefined1 *)(iStack_48 + 5);
      uStack_50 = *(undefined1 *)(iStack_48 + 0x11);
      uStack_4f = *(undefined1 *)(iStack_48 + 0x10);
      uStack_52 = *puStack_24;
      uStack_64._0_2_ = CONCAT11(uStack_2a,(undefined1)uStack_64);
      nwk_mm_beacon_notify_indication(*(undefined1 *)(iVar2 + 0x2c),&uStack_64);
      return;
    }
    uVar5 = (uint)(byte)*puStack_24;
    if (uVar5 != 4) {
      if (uVar5 < 5) {
        if (uVar5 == 1) {
          if ((*(byte *)(iVar2 + 0x2a) & 1) == 0) {
            return;
          }
          if (abStack_3a[0] != 3) {
            return;
          }
          uStack_64 = uStack_38;
          uStack_60 = uStack_34;
          uStack_5c = CONCAT11(uStack_5c._1_1_,*(byte *)((int)puStack_24 + 1));
          nwk_mm_asso_indication(*(undefined1 *)(iVar2 + 0x2c),&uStack_64);
          return;
        }
        if (uVar5 != 2) {
          return;
        }
        if ((*(uint *)(iVar2 + 0x2c) & 0xffff00) != 0x60200) {
          return;
        }
        if (cStack_44 == '\0') {
          return;
        }
        micro_timer_stop(iVar2 + 0x8c);
        *(undefined1 *)(iVar2 + 0x2e) = 0;
        if ((byte)*puStack_24 == 2) {
          uStack_64 = CONCAT13(uStack_64._3_1_,*(undefined3 *)((int)puStack_24 + 1));
          if (abStack_3a[0] == 3) {
            *(uint *)(iVar2 + 0x10) = uStack_38;
            *(uint *)(iVar2 + 0x14) = uStack_34;
          }
          mac_finish_association(iVar2,&uStack_64);
          mac_perform_next_op(iVar2);
          return;
        }
        uVar5 = __assert_func(0,0,0,0);
      }
      if (uVar5 != 7) {
        return;
      }
      uVar6 = 7;
      if (*(char *)(iVar2 + 0x23) == '\0') {
        return;
      }
_L0:
      mac_start_op(iVar2,uVar6);
      return;
    }
    memcpy(auStack_70,abStack_3a,10);
    nwk_mm_poll_indication(*(undefined1 *)(iVar2 + 0x2c),auStack_70);
    piVar3 = *(int **)(iVar2 + 0x60);
    do {
      if (piVar3 == (int *)(iVar2 + 0x60)) {
        return;
      }
      zmsg_get_footer(piVar3,&uStack_64,10);
      if ((uint)abStack_3a[0] == (uStack_64 & 0xff)) {
        if (abStack_3a[0] == 2) {
          uVar7 = uStack_38 & 0xffff;
          uVar5 = (uint)uStack_64._2_2_;
        }
        else {
          uVar7 = (uint)uStack_5c << 0x10 | uStack_60 >> 0x10;
          uVar5 = uStack_34;
          if (uStack_38 != (uStack_60 << 0x10 | (uint)uStack_64._2_2_)) goto _L0;
        }
        if (uVar5 == uVar7) {
          piVar8 = (int *)piVar3[1];
          iVar4 = *piVar3;
          *(int **)(iVar4 + 4) = piVar8;
          *piVar8 = iVar4;
          *piVar3 = 0;
          piVar3[1] = 0;
          zmsg_queue_enqueue(iVar2 + 0x54,piVar3);
          uVar6 = 8;
          goto _L0;
        }
      }
_L0:
      piVar3 = (int *)*piVar3;
    } while( true );
  }
  if (*(char *)(iVar2 + 0x2d) == '\x02') {
    return;
  }
  if ((cVar1 == '\x06') && (cStack_44 != '\0')) {
    if (abStack_3a[0] == 2) {
      uStack_34 = (uint)*(ushort *)(iVar2 + 0xe);
      uVar5 = uStack_38 & 0xffff;
    }
    else if ((abStack_3a[0] != 3) ||
            (uVar5 = *(uint *)(iVar2 + 0x14), uStack_38 != *(uint *)(iVar2 + 0x10))) goto _L0;
    if (uStack_34 == uVar5) {
      micro_timer_stop(iVar2 + 0x8c);
      *(undefined1 *)(iVar2 + 0x2e) = 0;
      mac_report_poll_result_constprop_0(iVar2,0);
      mac_perform_next_op(iVar2);
    }
  }
_L0:
  nwk_mm_data_indication(*(undefined1 *)(iVar2 + 0x2c),&iStack_48);
  return;
}

