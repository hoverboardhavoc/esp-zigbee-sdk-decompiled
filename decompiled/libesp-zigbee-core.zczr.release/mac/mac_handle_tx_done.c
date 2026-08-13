/*
 * Last changed at upstream commit ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * https://github.com/espressif/esp-zigbee-sdk/commit/ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * Upstream date: 2026-08-13 06:13:24 +0000
 * Upstream subject: change: update esp-zigbee-lib (e4bad48f)
 * Source: libesp-zigbee-core.zczr.release -> mac.o -> mac_handle_tx_done
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void mac_handle_tx_done(int param_1,undefined4 param_2,uint param_3,int param_4)

{
  short sVar1;
  undefined1 uVar2;
  int *piVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  int *piVar7;
  uint uVar8;
  int *piVar9;
  uint uVar10;
  int unaff_s7;
  undefined1 uStack_81;
  undefined4 uStack_80;
  uint uStack_7c;
  int iStack_78;
  undefined4 uStack_74;
  undefined4 uStack_70;
  undefined4 uStack_6c;
  int *piStack_68;
  undefined4 uStack_64;
  undefined2 uStack_60;
  undefined1 auStack_5e [10];
  undefined2 uStack_54;
  undefined1 uStack_52;
  char acStack_4c [2];
  ushort uStack_4a;
  uint uStack_48;
  ushort uStack_44;
  undefined1 auStack_42 [10];
  undefined2 uStack_38;
  ushort uStack_34;
  char cStack_31;
  
  piVar3 = (int *)zmsg_queue_get_head(param_2);
  if (piVar3 != (int *)0x0) {
    uStack_81 = 0;
    zmsg_queue_dequeue(param_2,piVar3);
    if (param_4 == 0) goto _L0;
    unaff_s7 = param_1 + 0x60;
    if ((param_3 & 0xfffffff7) == 0x1e1) {
      for (piVar9 = *(int **)(param_1 + 0x60);
          (piVar9 != (int *)unaff_s7 && (piVar9[6] - piVar3[6] < 0)); piVar9 = (int *)*piVar9) {
      }
      piVar7 = (int *)piVar9[1];
      piVar9[1] = (int)piVar3;
      *piVar3 = (int)piVar9;
      sVar1 = *(short *)(param_1 + 0x68);
      piVar3[1] = (int)piVar7;
      *piVar7 = (int)piVar3;
      *(short *)(param_1 + 0x68) = sVar1 + 1;
      if (piVar3 == *(int **)(param_1 + 0x60)) {
        micro_timer_fire_at(param_1 + 0x6c,piVar3[6]);
      }
    }
    else {
      zmsg_get_footer(piVar3,&uStack_80,10);
      if ((((uint)uStack_80 & 0xff) - 2 & 0xff) < 2) goto _L0;
      do {
        do {
          __assert_func(0,0,0,0);
_L0:
          piVar7 = *(int **)(param_1 + 0x60);
          piStack_68 = (int *)0x0;
          uStack_64 = 0;
          uStack_60 = 0;
          piVar9 = (int *)0x0;
          iVar6 = 0;
          for (; piVar7 != (int *)unaff_s7; piVar7 = (int *)*piVar7) {
            zmsg_get_footer(piVar7,acStack_4c,10);
            if ((char)uStack_80 == acStack_4c[0]) {
              if ((char)uStack_80 == '\x02') {
                uVar8 = (uint)uStack_4a;
                uVar10 = (uint)uStack_80._2_2_;
              }
              else {
                uVar8 = (uint)uStack_44 << 0x10 | uStack_48 >> 0x10;
                uVar10 = iStack_78 << 0x10 | uStack_7c >> 0x10;
                if ((uStack_48 << 0x10 | (uint)uStack_4a) !=
                    (uStack_7c << 0x10 | (uint)uStack_80._2_2_)) goto _L0;
              }
              if (uVar8 == uVar10) goto _L0;
            }
_L0:
            iVar4 = iVar6;
            if (((*(ushort *)((int)piVar7 + 0x16) & 0x40) == 0) &&
               (iVar4 = param_4, piVar9 == (int *)0x0)) {
              memcpy(&piStack_68,acStack_4c,10);
              piVar9 = piVar7;
              iVar4 = iVar6;
            }
            iVar6 = iVar4;
          }
          mac_pal_src_match_remove(&uStack_80);
          if (piVar9 != (int *)0x0) {
            iVar4 = mac_pal_src_match_add(&piStack_68);
            if (iVar4 == 0) {
              *(ushort *)((int)piVar9 + 0x16) = *(ushort *)((int)piVar9 + 0x16) | 0x40;
              if (iVar6 != 0) goto _L0;
              uVar5 = 1;
            }
            else {
              uVar5 = 0;
            }
            mac_pal_src_match_set_enabled(uVar5);
          }
_L0:
          zmsg_remove_footer(piVar3,10);
_L0:
          memset(&piStack_68,0,0x1a);
          uStack_7c = 0;
          iStack_78 = 0;
          uStack_74 = 0;
          uStack_70 = 0;
          uStack_6c = 0;
          uStack_80 = &piStack_68;
          uVar2 = zmsg_read_bytes(piVar3,0,0x1a,&piStack_68);
          uStack_7c = CONCAT31(uStack_7c._1_3_,uVar2);
          iVar6 = mac_frame_parse_header(&uStack_80,acStack_4c,&uStack_81);
        } while (iVar6 != 0);
        zmsg_remove_header(piVar3,uStack_81);
        uStack_52 = (undefined1)param_3;
        if (cStack_31 == '\x02') {
          memcpy(&piStack_68,auStack_42,10);
          memcpy(auStack_5e,acStack_4c,10);
          uStack_54 = uStack_38;
          nwk_mm_comm_status_indication(*(undefined1 *)(param_1 + 0x2c),&piStack_68);
          zmsg_free(piVar3);
          return;
        }
      } while ((uStack_34 & 7) != 1);
      uVar8 = (uint)uStack_64 >> 8;
      uStack_64._0_2_ = CONCAT11((byte)uVar8 & 0xfe | (byte)param_4 & 1,uStack_52);
      piStack_68 = piVar3;
      nwk_mm_data_confirm(*(undefined1 *)(param_1 + 0x2c),&piStack_68);
    }
  }
  return;
}

