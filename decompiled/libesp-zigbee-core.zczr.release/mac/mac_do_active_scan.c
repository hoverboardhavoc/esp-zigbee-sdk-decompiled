/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> mac.o -> mac_do_active_scan
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void mac_do_active_scan(void *param_1)

{
  byte bVar1;
  ushort uVar2;
  char cVar3;
  int *piVar4;
  undefined1 *puVar5;
  int iVar6;
  undefined2 uVar7;
  uint uVar8;
  int iVar9;
  undefined4 unaff_s3;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  
  while( true ) {
    if (((*(uint *)((int)param_1 + 0x9c) & 1) != 0) &&
       (iVar6 = mac_update_scan_channel_part_0(), iVar6 == 0)) goto mac_do_transmit_part_0;
    mac_pal_set_panid(*(undefined2 *)((int)param_1 + 10));
    mac_pal_set_rx_when_idle(*(uint *)((int)param_1 + 0x28) >> 0x11 & 1);
    *(undefined1 *)((int)param_1 + 0x2d) = 0;
    *(undefined1 *)((int)param_1 + 0x2e) = 0;
    if (*(code **)((int)param_1 + 0x38) != (code *)0x0) {
      (**(code **)((int)param_1 + 0x38))(0,*(undefined4 *)((int)param_1 + 0x3c));
    }
    if ((*(uint *)((int)param_1 + 0x9c) & 1) == 0) {
      return;
    }
    if (*(char *)((int)param_1 + 0x2e) != '\0') {
      return;
    }
    uVar2 = *(ushort *)((int)param_1 + 0x30);
    if ((uVar2 & 0x40) == 0) {
      if ((uVar2 & 2) == 0) {
        if ((uVar2 & 4) == 0) {
          if ((uVar2 & 8) == 0) {
            if ((uVar2 & 0x80) == 0) {
              if ((uVar2 & 0x100) == 0) {
                if ((uVar2 & 0x20) == 0) {
                  uVar8 = 4;
                  if ((uVar2 & 0x10) == 0) {
                    if (*(char *)((int)param_1 + 0x2e) != '\0') {
                      return;
                    }
                    if (-1 < *(int *)((int)param_1 + 0x28) << 0xe) {
                      mac_pal_sleep();
                      return;
                    }
                    mac_pal_receive(*(undefined1 *)((int)param_1 + 0x42),
                                    *(undefined1 *)((int)param_1 + 0x41));
                    return;
                  }
                }
                else {
                  uVar8 = 5;
                }
              }
              else {
                uVar8 = 8;
              }
            }
            else {
              uVar8 = 7;
            }
          }
          else {
            uVar8 = 3;
          }
        }
        else {
          uVar8 = 2;
        }
      }
      else {
        uVar8 = 1;
      }
    }
    else {
      uVar8 = 6;
    }
    *(ushort *)((int)param_1 + 0x30) = uVar2 & ~(ushort)(1 << uVar8);
    *(char *)((int)param_1 + 0x2e) = (char)uVar8;
    uStack_14 = unaff_s3;
    micro_timer_stop((int)param_1 + 0x8c);
    if (5 < uVar8) {
      if (uVar8 == 6) {
        mac_pal_receive(*(undefined1 *)((int)param_1 + 0x42),*(undefined1 *)((int)param_1 + 0x41));
        micro_timer_start((int)param_1 + 0x8c,
                          ((*(ushort *)((int)param_1 + 0x1c) + 0x3bf) / 0x3c0 + 1) * 0x3c00);
        return;
      }
      goto _L0;
    }
    if (3 < uVar8) goto _L0;
    if (uVar8 == 2) {
      *(undefined1 *)((int)param_1 + 0x2d) = 1;
      mac_do_ed_scan(param_1);
      return;
    }
    if (uVar8 == 3) break;
    *(undefined1 *)((int)param_1 + 0x2d) = 1;
    unaff_s3 = uStack_14;
  }
  *(undefined1 *)((int)param_1 + 0x2d) = 2;
_L0:
  if ((*(uint *)((int)param_1 + 0x9c) & 1) == 0) {
    return;
  }
mac_do_transmit_part_0:
  piVar4 = (int *)mac_pal_get_tx_frame();
  *(undefined1 *)((int)piVar4 + 5) = *(undefined1 *)((int)param_1 + 0x41);
  *(undefined1 *)(piVar4 + 4) = *(undefined1 *)((int)param_1 + 0x1e);
  *(undefined1 *)((int)piVar4 + 0x11) = *(undefined1 *)((int)param_1 + 0x22);
  *(undefined1 *)((int)piVar4 + 0x12) = *(undefined1 *)((int)param_1 + 0x21);
  *(undefined1 *)((int)piVar4 + 0x13) = *(undefined1 *)((int)param_1 + 0x20);
  bVar1 = *(byte *)((int)param_1 + 0x2e);
  uVar8 = (uint)bVar1;
  if (uVar8 == 5) {
    mac_pal_set_rx_when_idle(1);
    uVar8 = 3;
    uStack_24 = CONCAT31(uStack_24._1_3_,3);
    memcpy((void *)((int)&uStack_24 + 2),param_1,8);
    uStack_18 = *(undefined4 *)((int)param_1 + 0x10);
    uStack_1c._0_3_ = CONCAT12(3,(undefined2)uStack_1c);
    uStack_14 = *(undefined4 *)((int)param_1 + 0x14);
    uStack_28 = CONCAT22(*(undefined2 *)((int)param_1 + 10),*(undefined2 *)((int)param_1 + 10));
    if (*(ushort *)((int)param_1 + 0xe) < 0xfffe) {
      uStack_1c._0_3_ = CONCAT12(2,(undefined2)uStack_1c);
      uStack_18._2_2_ = (undefined2)((uint)uStack_18 >> 0x10);
      uStack_18 = CONCAT22(uStack_18._2_2_,*(ushort *)((int)param_1 + 0xe));
    }
    if (*(ushort *)((int)param_1 + 8) < 0xfffe) {
      uStack_24 = CONCAT31(uStack_24._1_3_,2);
      uStack_24 = CONCAT22(*(ushort *)((int)param_1 + 8),(undefined2)uStack_24);
    }
    cVar3 = mac_frame_write_hdr(*piVar4,&uStack_24,&uStack_28,0,3,4);
    *(char *)(piVar4 + 1) = cVar3 + '\x02';
    goto _L0;
  }
  if (5 < uVar8) goto _L0;
  if (uVar8 == 3) {
    uStack_24 = CONCAT31(uStack_24._1_3_,bVar1);
    memcpy((void *)((int)&uStack_24 + 2),param_1,8);
    uStack_18 = *(undefined4 *)((int)param_1 + 0x10);
    uStack_1c._0_3_ = CONCAT12(bVar1,(undefined2)uStack_1c);
    uStack_14 = *(undefined4 *)((int)param_1 + 0x14);
    uStack_28 = CONCAT22(*(undefined2 *)((int)param_1 + 10),0xffff);
    if (*(ushort *)((int)param_1 + 0xe) < 0xfffe) {
      uStack_1c._0_3_ = CONCAT12(2,(undefined2)uStack_1c);
      uStack_18._2_2_ = (undefined2)((uint)uStack_18 >> 0x10);
      uStack_18 = CONCAT22(uStack_18._2_2_,*(ushort *)((int)param_1 + 0xe));
    }
    cVar3 = mac_frame_write_hdr(*piVar4,&uStack_24,&uStack_28,0,3,1);
    *(char *)(piVar4 + 1) = cVar3 + '\x02';
    *(char *)((int)param_1 + 0xc) = *(char *)((int)param_1 + 0xc) + '\x01';
    mac_frame_set_seq_num(piVar4);
    iVar9 = *piVar4;
    iVar6 = mac_frame_find_payload_index(piVar4);
    uVar8 = iVar9 + iVar6;
    *(undefined1 *)(uVar8 + 1) = *(undefined1 *)((int)param_1 + 0x40);
    *(char *)(piVar4 + 1) = (char)piVar4[1] + '\x01';
    goto _L0;
  }
  if (uVar8 == 4) {
    iVar6 = (int)param_1 + 0x48;
    goto _L0;
  }
  if (uVar8 == 1) {
    uStack_1c = 0x20000;
    uStack_18 = 0xffff;
    uStack_28 = 0xffffffff;
    uStack_24 = 0;
    uStack_20 = 0;
    uStack_14 = 0;
    cVar3 = mac_frame_write_hdr(*piVar4,&uStack_24,&uStack_28,0,7);
    *(char *)(piVar4 + 1) = cVar3 + '\x02';
    *(char *)((int)param_1 + 0xc) = *(char *)((int)param_1 + 0xc) + '\x01';
    mac_frame_set_seq_num(piVar4);
    mac_pal_set_panid(0xffff);
    mac_pal_set_rx_when_idle(1);
    *(undefined1 *)((int)piVar4 + 5) = *(undefined1 *)((int)param_1 + 0x32);
    goto _L0;
  }
_L0:
  do {
    __assert_func(0,0,0,0);
_L0:
    if (uVar8 == 7) {
      memset((void *)((int)&uStack_24 + 1),0,0x13);
      uStack_24 = CONCAT31(uStack_24._1_3_,2);
      uStack_24 = CONCAT22(*(undefined2 *)((int)param_1 + 8),(undefined2)uStack_24);
      uStack_28 = CONCAT22(0xffff,*(undefined2 *)((int)param_1 + 10));
      cVar3 = mac_frame_write_hdr(*piVar4,&uStack_24,&uStack_28,0,0,0);
      *(char *)(piVar4 + 1) = cVar3 + '\x02';
      *(char *)((int)param_1 + 0xd) = *(char *)((int)param_1 + 0xd) + '\x01';
      mac_frame_set_seq_num(piVar4);
      iVar9 = *piVar4;
      iVar6 = mac_frame_find_payload_index(piVar4);
      uVar2 = *(ushort *)((int)param_1 + 0x2a);
      puVar5 = (undefined1 *)(iVar6 + iVar9);
      if ((*(short *)((int)param_1 + 0xe) == -1) ||
         (uVar7 = 0x4fff, *(short *)((int)param_1 + 8) != *(short *)((int)param_1 + 0xe))) {
        uVar7 = 0xfff;
      }
      *puVar5 = (char)uVar7;
      puVar5[2] = 0;
      puVar5[3] = 0;
      puVar5[1] = (byte)(((uVar2 & 1) << 0xf) >> 8) | (byte)((ushort)uVar7 >> 8);
      uVar8 = 0;
      *(char *)(piVar4 + 1) = (char)piVar4[1] + '\x04';
      if ((*(void **)((int)param_1 + 0x24) != (void *)0x0) &&
         (uVar8 = (uint)*(byte *)((int)param_1 + 0x23), uVar8 != 0)) {
        memcpy(puVar5 + 4,*(void **)((int)param_1 + 0x24),uVar8);
      }
      uVar8 = uVar8 + *(byte *)(piVar4 + 1);
      *(char *)(piVar4 + 1) = (char)uVar8;
    }
    else {
      iVar6 = (int)param_1 + 0x54;
      if (uVar8 != 8) goto _L0;
_L0:
      iVar6 = zmsg_queue_get_head(iVar6);
      if (iVar6 == 0) goto _L0;
      txframe_from_zmsg_isra_0(piVar4);
_L0:
      *(char *)((int)param_1 + 0xc) = *(char *)((int)param_1 + 0xc) + '\x01';
      mac_frame_set_seq_num(piVar4);
    }
_L0:
    iVar6 = mac_pal_transmit();
    if (iVar6 == 0) {
      return;
    }
  } while( true );
}

