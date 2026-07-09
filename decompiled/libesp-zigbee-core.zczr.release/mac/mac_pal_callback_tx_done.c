/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> mac.o -> mac_pal_callback_tx_done
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void mac_pal_callback_tx_done(undefined4 *param_1,undefined4 *param_2,uint param_3)

{
  ushort uVar1;
  void *__src;
  uint uVar2;
  char cVar3;
  int *piVar4;
  undefined1 *puVar5;
  byte bVar6;
  undefined4 uVar7;
  undefined2 uVar8;
  int iVar9;
  int iVar10;
  undefined4 unaff_s3;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  
  __src = s_devices;
  bVar6 = *(byte *)((int)s_devices + 0x2e);
  if (bVar6 == 5) {
    if ((*(char *)(param_1 + 1) != '\0') && ((*(ushort *)*param_1 & 0x20) == 0)) {
_L0:
      do {
        __assert_func(0,0,0,0);
_L0:
        if (bVar6 == 7) {
          *(undefined1 *)((int)__src + 0x2e) = 0;
          goto mac_perform_next_op;
        }
      } while (bVar6 != 8);
      *(undefined1 *)((int)__src + 0x2e) = 0;
      iVar10 = (int)__src + 0x54;
      uVar7 = 1;
      goto _L0;
    }
    *(undefined1 *)((int)s_devices + 0x2e) = 0;
    if (param_3 != 0) {
_L0:
      mac_report_poll_result_constprop_0(__src,param_3 & 0xff);
      goto mac_perform_next_op;
    }
    if (param_2 == (undefined4 *)0x0) goto mac_perform_next_op;
    bVar6 = 6;
    param_3 = 0x1eb;
    if ((*(ushort *)*param_2 & 0x10) == 0) goto _L0;
  }
  else {
    if (5 < bVar6) goto _L0;
    if (bVar6 == 3) {
      iVar10 = (uint)*(byte *)((int)s_devices + 0x1f) * 0x3c00;
_L0:
      micro_timer_start((int)s_devices + 0x8c,iVar10);
      return;
    }
    if (bVar6 != 4) {
      if (bVar6 == 1) {
        uVar2 = ((1 << (*(byte *)((int)s_devices + 0x33) & 0x1f)) + 1) * 0x3c00;
        iVar10 = uVar2 - uVar2 % 1000;
        goto _L0;
      }
      goto _L0;
    }
    *(undefined1 *)((int)s_devices + 0x2e) = 0;
    iVar10 = (int)__src + 0x48;
    uVar7 = 0;
_L0:
    mac_handle_tx_done(__src,iVar10,uVar7);
    iVar10 = zmsg_queue_get_head(iVar10);
    if (iVar10 == 0) goto mac_perform_next_op;
  }
  mac_start_op(__src,bVar6);
mac_perform_next_op:
  do {
    if ((*(uint *)((int)__src + 0x9c) & 1) == 0) {
      return;
    }
    if (*(char *)((int)__src + 0x2e) != '\0') {
      return;
    }
    uVar1 = *(ushort *)((int)__src + 0x30);
    if ((uVar1 & 0x40) == 0) {
      if ((uVar1 & 2) == 0) {
        if ((uVar1 & 4) == 0) {
          if ((uVar1 & 8) == 0) {
            if ((uVar1 & 0x80) == 0) {
              if ((uVar1 & 0x100) == 0) {
                if ((uVar1 & 0x20) == 0) {
                  uVar2 = 4;
                  if ((uVar1 & 0x10) == 0) {
                    if (*(char *)((int)__src + 0x2e) != '\0') {
                      return;
                    }
                    if (*(int *)((int)__src + 0x28) << 0xe < 0) {
                      mac_pal_receive(*(undefined1 *)((int)__src + 0x42),
                                      *(undefined1 *)((int)__src + 0x41));
                      return;
                    }
                    mac_pal_sleep();
                    return;
                  }
                }
                else {
                  uVar2 = 5;
                }
              }
              else {
                uVar2 = 8;
              }
            }
            else {
              uVar2 = 7;
            }
          }
          else {
            uVar2 = 3;
          }
        }
        else {
          uVar2 = 2;
        }
      }
      else {
        uVar2 = 1;
      }
    }
    else {
      uVar2 = 6;
    }
    *(ushort *)((int)__src + 0x30) = uVar1 & ~(ushort)(1 << uVar2);
    *(char *)((int)__src + 0x2e) = (char)uVar2;
    uStack_14 = unaff_s3;
    micro_timer_stop((int)__src + 0x8c);
    unaff_s3 = uStack_14;
    if (5 < uVar2) {
      if (uVar2 == 6) {
        mac_pal_receive(*(undefined1 *)((int)__src + 0x42),*(undefined1 *)((int)__src + 0x41));
        micro_timer_start((int)__src + 0x8c,
                          ((*(ushort *)((int)__src + 0x1c) + 0x3bf) / 0x3c0 + 1) * 0x3c00);
        return;
      }
_L0:
      if ((*(uint *)((int)__src + 0x9c) & 1) == 0) {
        return;
      }
mac_do_transmit_part_0:
      piVar4 = (int *)mac_pal_get_tx_frame();
      *(undefined1 *)((int)piVar4 + 5) = *(undefined1 *)((int)__src + 0x41);
      *(undefined1 *)(piVar4 + 4) = *(undefined1 *)((int)__src + 0x1e);
      *(undefined1 *)((int)piVar4 + 0x11) = *(undefined1 *)((int)__src + 0x22);
      *(undefined1 *)((int)piVar4 + 0x12) = *(undefined1 *)((int)__src + 0x21);
      *(undefined1 *)((int)piVar4 + 0x13) = *(undefined1 *)((int)__src + 0x20);
      bVar6 = *(byte *)((int)__src + 0x2e);
      uVar2 = (uint)bVar6;
      if (uVar2 == 5) {
        mac_pal_set_rx_when_idle(1);
        uVar2 = 3;
        uStack_24 = CONCAT31(uStack_24._1_3_,3);
        memcpy((void *)((int)&uStack_24 + 2),__src,8);
        uStack_18 = *(undefined4 *)((int)__src + 0x10);
        uStack_1c._0_3_ = CONCAT12(3,(undefined2)uStack_1c);
        uStack_14 = *(undefined4 *)((int)__src + 0x14);
        uStack_28 = CONCAT22(*(undefined2 *)((int)__src + 10),*(undefined2 *)((int)__src + 10));
        if (*(ushort *)((int)__src + 0xe) < 0xfffe) {
          uStack_1c._0_3_ = CONCAT12(2,(undefined2)uStack_1c);
          uStack_18._2_2_ = (undefined2)((uint)uStack_18 >> 0x10);
          uStack_18 = CONCAT22(uStack_18._2_2_,*(ushort *)((int)__src + 0xe));
        }
        if (*(ushort *)((int)__src + 8) < 0xfffe) {
          uStack_24 = CONCAT31(uStack_24._1_3_,2);
          uStack_24 = CONCAT22(*(ushort *)((int)__src + 8),(undefined2)uStack_24);
        }
        cVar3 = mac_frame_write_hdr(*piVar4,&uStack_24,&uStack_28,0,3,4);
        *(char *)(piVar4 + 1) = cVar3 + '\x02';
        goto _L0;
      }
      if (5 < uVar2) goto _L0;
      if (uVar2 == 3) {
        uStack_24 = CONCAT31(uStack_24._1_3_,bVar6);
        memcpy((void *)((int)&uStack_24 + 2),__src,8);
        uStack_18 = *(undefined4 *)((int)__src + 0x10);
        uStack_1c._0_3_ = CONCAT12(bVar6,(undefined2)uStack_1c);
        uStack_14 = *(undefined4 *)((int)__src + 0x14);
        uStack_28 = CONCAT22(*(undefined2 *)((int)__src + 10),0xffff);
        if (*(ushort *)((int)__src + 0xe) < 0xfffe) {
          uStack_1c._0_3_ = CONCAT12(2,(undefined2)uStack_1c);
          uStack_18._2_2_ = (undefined2)((uint)uStack_18 >> 0x10);
          uStack_18 = CONCAT22(uStack_18._2_2_,*(ushort *)((int)__src + 0xe));
        }
        cVar3 = mac_frame_write_hdr(*piVar4,&uStack_24,&uStack_28,0,3,1);
        *(char *)(piVar4 + 1) = cVar3 + '\x02';
        *(char *)((int)__src + 0xc) = *(char *)((int)__src + 0xc) + '\x01';
        mac_frame_set_seq_num(piVar4);
        iVar9 = *piVar4;
        iVar10 = mac_frame_find_payload_index(piVar4);
        uVar2 = iVar9 + iVar10;
        *(undefined1 *)(uVar2 + 1) = *(undefined1 *)((int)__src + 0x40);
        *(char *)(piVar4 + 1) = (char)piVar4[1] + '\x01';
        goto _L0;
      }
      if (uVar2 == 4) {
        iVar10 = (int)__src + 0x48;
        goto _L0;
      }
      if (uVar2 == 1) {
        uStack_1c = 0x20000;
        uStack_18 = 0xffff;
        uStack_28 = 0xffffffff;
        uStack_24 = 0;
        uStack_20 = 0;
        uStack_14 = 0;
        cVar3 = mac_frame_write_hdr(*piVar4,&uStack_24,&uStack_28,0,7);
        *(char *)(piVar4 + 1) = cVar3 + '\x02';
        *(char *)((int)__src + 0xc) = *(char *)((int)__src + 0xc) + '\x01';
        mac_frame_set_seq_num(piVar4);
        mac_pal_set_panid(0xffff);
        mac_pal_set_rx_when_idle(1);
        *(undefined1 *)((int)piVar4 + 5) = *(undefined1 *)((int)__src + 0x32);
        goto _L0;
      }
      break;
    }
    if (3 < uVar2) goto _L0;
    if (uVar2 == 2) {
      *(undefined1 *)((int)__src + 0x2d) = 1;
      mac_do_ed_scan(__src);
      return;
    }
    if (uVar2 == 3) {
      *(undefined1 *)((int)__src + 0x2d) = 2;
      goto _L0;
    }
    *(undefined1 *)((int)__src + 0x2d) = 1;
    if (((*(uint *)((int)__src + 0x9c) & 1) != 0) &&
       (iVar10 = mac_update_scan_channel_part_0(), iVar10 == 0)) goto mac_do_transmit_part_0;
    mac_pal_set_panid(*(undefined2 *)((int)__src + 10));
    mac_pal_set_rx_when_idle(*(uint *)((int)__src + 0x28) >> 0x11 & 1);
    *(undefined1 *)((int)__src + 0x2d) = 0;
    *(undefined1 *)((int)__src + 0x2e) = 0;
    if (*(code **)((int)__src + 0x38) != (code *)0x0) {
      (**(code **)((int)__src + 0x38))(0,*(undefined4 *)((int)__src + 0x3c));
    }
  } while( true );
_L0:
  __assert_func(0,0,0,0);
_L0:
  if (uVar2 == 7) {
    memset((void *)((int)&uStack_24 + 1),0,0x13);
    uStack_24 = CONCAT31(uStack_24._1_3_,2);
    uStack_24 = CONCAT22(*(undefined2 *)((int)__src + 8),(undefined2)uStack_24);
    uStack_28 = CONCAT22(0xffff,*(undefined2 *)((int)__src + 10));
    cVar3 = mac_frame_write_hdr(*piVar4,&uStack_24,&uStack_28,0,0,0);
    *(char *)(piVar4 + 1) = cVar3 + '\x02';
    *(char *)((int)__src + 0xd) = *(char *)((int)__src + 0xd) + '\x01';
    mac_frame_set_seq_num(piVar4);
    iVar9 = *piVar4;
    iVar10 = mac_frame_find_payload_index(piVar4);
    uVar1 = *(ushort *)((int)__src + 0x2a);
    puVar5 = (undefined1 *)(iVar10 + iVar9);
    if ((*(short *)((int)__src + 0xe) == -1) ||
       (uVar8 = 0x4fff, *(short *)((int)__src + 8) != *(short *)((int)__src + 0xe))) {
      uVar8 = 0xfff;
    }
    *puVar5 = (char)uVar8;
    puVar5[2] = 0;
    puVar5[3] = 0;
    puVar5[1] = (byte)(((uVar1 & 1) << 0xf) >> 8) | (byte)((ushort)uVar8 >> 8);
    uVar2 = 0;
    *(char *)(piVar4 + 1) = (char)piVar4[1] + '\x04';
    if ((*(void **)((int)__src + 0x24) != (void *)0x0) &&
       (uVar2 = (uint)*(byte *)((int)__src + 0x23), uVar2 != 0)) {
      memcpy(puVar5 + 4,*(void **)((int)__src + 0x24),uVar2);
    }
    uVar2 = uVar2 + *(byte *)(piVar4 + 1);
    *(char *)(piVar4 + 1) = (char)uVar2;
  }
  else {
    iVar10 = (int)__src + 0x54;
    if (uVar2 != 8) goto _L0;
_L0:
    iVar10 = zmsg_queue_get_head(iVar10);
    if (iVar10 == 0) goto _L0;
    txframe_from_zmsg_isra_0(piVar4);
_L0:
    *(char *)((int)__src + 0xc) = *(char *)((int)__src + 0xc) + '\x01';
    mac_frame_set_seq_num(piVar4);
  }
_L0:
  iVar10 = mac_pal_transmit();
  if (iVar10 == 0) {
    return;
  }
  goto _L0;
}

